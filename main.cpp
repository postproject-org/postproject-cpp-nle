#include <postproject/postproject.hpp>

#include <iostream>
#include <string>

struct TimelineClip final {
  std::string postproject_reference;
  std::string fallback_path;
};

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "usage: postproject-cpp-nle-validation PRODUCTION MEDIA\n";
    return 2;
  }

  try {
    auto production =
        postproject::Production::create(argv[1], "C++ NLE validation").value();
    auto transaction = production.edit().value();
    const auto imported = transaction.importMedia(argv[2], "Timeline clip").value();
    const auto asset_id = imported.asset_id;
    transaction.commit().value();

    const postproject::HostObjectBinding binding{
        production.id().value(),
        postproject::ObjectRef::representation(imported.representation_id)};
    const TimelineClip clip{binding.toString().value(), argv[2]};
    if (!(postproject::HostObjectBinding::fromString(
              clip.postproject_reference).value() == binding)) {
      throw std::runtime_error("host binding did not round-trip");
    }

    const auto resolutions = production.resolveAsset(asset_id).value();
    if (resolutions.size() != 1 ||
        resolutions[0].availability !=
            postproject::RepresentationAvailability::online) {
      throw std::runtime_error("timeline clip did not resolve online");
    }
    std::cout << clip.postproject_reference << '\n';
    return 0;
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
