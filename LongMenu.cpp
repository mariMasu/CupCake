//
//  LongMenu.cpp
//  MakingCupcakes
//
//  Created by 枡岡真里 on 2016/05/09.
//
//

#include "LongMenu.hpp"
#include "audio/include/SimpleAudioEngine.h"

USING_NS_CC;


LongMenu::LongMenu(){
    
}

LongMenu::~LongMenu(){
    
}

bool LongMenu::init(){
    
    if (!MenuItemImage::init()) {
        return false;
    }
    
    return true;
}

LongMenu * LongMenu::create(const std::string& normalImage, const std::string& selectedImage, const ccMenuCallback& callback)
{
    return LongMenu::create(normalImage, selectedImage, "", callback);
}

LongMenu * LongMenu::create(const std::string& normalImage, const std::string& selectedImage, const std::string& disabledImage, const ccMenuCallback& callback)
{
    LongMenu *ret = new (std::nothrow) LongMenu();
    if (ret && ret->initWithNormalImage(normalImage, selectedImage, disabledImage, callback))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void LongMenu::selected()
{
    _selected = true;
    
    if(_ended != true){
    _touchT = 0;
    this->schedule(schedule_selector(LongMenu::sche),0.1);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("drum.mp3");
    
    auto action1 = RotateTo::create(0.08, -10);
    auto action2 = RotateTo::create(0.08, 10);
    auto action3 = RotateTo::create(0.08, 0);
    
    auto actions = Sequence::create(action1,action2,action3, NULL);
    auto repeat = RepeatForever::create(actions);
    
    this->runAction(repeat);
    }
    
}

void LongMenu::unselected()
{
    _selected = false;
    
    if(_ended != true){
    unschedule(schedule_selector(LongMenu::sche));
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
    this->stopAllActions();
    }

}

void LongMenu::sche(float dt){
    
    _touchT += 0.1;
    
    if(_touchT > 2.6 && _ended != true){
        unschedule(schedule_selector(LongMenu::sche));
        CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("cymbal.mp3");
        
        this->stopAllActions();
        this->setOpacity(0);
        this->setPosition(Vec2(10000, 10000));
        _end = true;
    }
    
}