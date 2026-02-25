#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(LevelSearchLayer){
  bool init(int p0){
    if (!LevelSearchLayer::init(p0)) {
      return false;
    }

    addEventListener(KeybindSettingPressedEventV3(GEODE_MOD_ID, "enterSearch"), [this](const Keybind& keybind, bool down, bool repeat,  double timestamp) {
      auto levelSearch = CCDirector::get()->getRunningScene()->getChildByID("LevelSearchLayer");
      if (down && !repeat && levelSearch != nullptr) {
        this->onSearch(nullptr);
      }
    });

    return true;
  }
};
