//
//  Page3.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Page3.hpp"

#include "Page2.hpp"
#include "Page4.hpp"
#include "Tools.hpp"

#include "audio/include/SimpleAudioEngine.h"


USING_NS_CC;


Page3::Page3(){
    
}

Page3::~Page3(){
    
}

bool Page3::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = Label::createWithSystemFont("Add the milk and egg", "Marker Felt", 50);
    
    titleLabel->setColor(Color3B(0,160,210));
    titleLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    titleLabel->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabel, 2);
    
    
    
    auto photo = MenuItemImage::create("CupcakeMake2.png","CupcakeMake2.png",
                                       [](Ref* ref){
                                           CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("boyon1.mp3");
                                       });
    
    photo->setScale(1.2);
    photo->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    
    auto photoMenu = Menu::create(photo, NULL);
    photoMenu->setPosition(0, 0);
    this->addChild(photoMenu);
    
    
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                          auto scene = Page4::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                          auto scene = Page2::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,true);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    back->setScale(0.8);
    back->setPosition(Vec2(winSize.width / 2 * 0.2, winSize.height / 1.1));
    
    
    auto Button = Menu::create(next,back, NULL);
    Button->setPosition(0, 0);
    this->addChild(Button);
    
    
    
    return true;
}

Scene* Page3::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page3::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}