//
//  Tools.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Tools.hpp"
#include "CupcakeTitle.hpp"

#include "audio/include/SimpleAudioEngine.h"

USING_NS_CC;


Tools::Tools(){
    
}

Tools::~Tools(){
    
}

bool Tools::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    _winSize = Director::getInstance()->getWinSize();
    
    return true;
}


void Tools::addBackGround(Layer *layer){
    
    auto background = Sprite::create("CupcakeBackground.png");
    background->setPosition(Vec2(_winSize.width / 2.0, _winSize.height / 2.0));
    layer->addChild(background);
    
    
}

void Tools::addTitleFrame(Layer *layer){
    
    
    auto titleFrame = Sprite::create("CupcakeFrame.png");
            
    titleFrame->setScale(0.5, 0.3);
    titleFrame->setPosition(Vec2(_winSize.width / 2.0, _winSize.height / 1.1));
    
    layer->addChild(titleFrame);
}

void Tools::addNext(Layer *layer,int tag){
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png");
    next->setScale(0.8);
    next->setPosition(Vec2(_winSize.width / 2 * 1.8, _winSize.height / 1.1));
    
    auto Button = Menu::create(next,NULL);
    Button->setPosition(0, 0);
    Button->setTag(tag);
    layer->addChild(Button);
    
}
                                      
void Tools::addBack(Layer *layer,int tag){
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png");
    back->setScale(0.8);
    back->setPosition(Vec2(_winSize.width / 2 * 0.2, _winSize.height / 1.1));
    
    auto Button = Menu::create(back,NULL);
    Button->setPosition(0, 0);
    Button->setTag(tag);

    layer->addChild(Button);
    
}

cocos2d::Label* Tools::blueLabel(std::string str,int size,bool dark){
    
    cocos2d::Label *label = cocos2d::Label::createWithSystemFont(str, "Marker Felt", size);
    
    if(dark){
        label->setColor(Color3B(0,160,210));
        label->enableOutline(Color4B(0, 160, 210, 255),5);
    }else{
        label->setColor(Color3B(255,255,255));
        label->enableOutline(Color4B(0, 160, 210, 255),5);
    }
    return label;
    
}

void Tools::playSound(enum sound kind){
    
    std::string path;
    float volume = 1;
    
    switch(kind)
    {
        case sound::TAP1:{
            path = "tap1.mp3";
            volume = 0.5;
            break;
        }
         
        case sound::TAP2:{
            path = "tap2.mp3";
            break;
        }
        case sound::TAP3:{
            path = "tap3.mp3";
            break;
        }
        case sound::BOYON:{
            path = "boyon.mp3";
            break;
        }
        case sound::KURUN:{
            path = "kurun.mp3";
            break;
        }
        case sound::MILK:{
            path = "milk.mp3";
            break;
        }
        case sound::BUTTER:{
            path = "butter.mp3";
            break;
        }
        case sound::SUGAR:{
            path = "sugar.mp3";
            break;
        }
        case sound::BAKINGP:{
            path = "bakingP.mp3";
            break;
        }
        case sound::FLOUR:{
            path = "flour.mp3";
            break;
        }
        case sound::EGG:{
            path = "egg.mp3";
            break;
        }
            
        case sound::P0:{
            path = "Making_Cup.mp3";
            break;
        }
        case sound::P1:{
            path = "Ingredient.mp3";
            break;
        }
        case sound::P2:{
            path = "Mix_the.mp3";
            break;
        }
        case sound::P3:{
            path = "Add_the.mp3";
            break;
        }
        case sound::P4:{
            path = "Shift_the.mp3";
            break;
        }
        case sound::P5:{
            path = "Bake_for.mp3";
            break;
        }
        case sound::P6:{
            path = "Congratulations!.mp3";
            break;
        }
    
    
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path.c_str());
    
}

void Tools::customAction(cocos2d::Ref *item,int num){
    
    auto actionItem = static_cast<Node*>(item);
    
    if(actionItem->getNumberOfRunningActions()==0){
        if(num == 1){
            
            auto action1 = RotateTo::create(0.2, -15);
            auto action2 = RotateTo::create(0.2, 15);
            auto action3 = RotateTo::create(0.2, 0);
            
            auto actions = Sequence::create(action1,action2,action3, NULL);
            
            actionItem->runAction(actions);
            
        }else{
        }
    }
}


