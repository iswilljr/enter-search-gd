#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>

using namespace geode::prelude;

$execute {
  using namespace keybinds;

  BindManager::get()->registerBindable({
    "enter-search"_spr,
    "Enter Search",
    "Search when you press enter in the level search page",
    { Keybind::create(KEY_Enter, Modifier::None) },
    "Enter Search"
  });
}

class $modify(LevelSearchLayer){
  bool init(int p0){
    if (!LevelSearchLayer::init(p0)) {
      return false;
    }

    this->template addEventListener<keybinds::InvokeBindFilter>([=](keybinds::InvokeBindEvent* event) {
      auto levelSearch = CCDirector::get()->getRunningScene()->getChildByID("LevelSearchLayer");

      if (event->isDown() && levelSearch != nullptr) {
        this->onSearch(nullptr);
      }
      return ListenerResult::Propagate;
    }, "enter-search"_spr);

    return true;
  }
};
