//
//  Page4.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Page4.hpp"

#include "Page3.hpp"

#include "Page5.hpp"
#include "Tools.hpp"

#include "audio/include/SimpleAudioEngine.h"



USING_NS_CC;


Page4::Page4(){
    
}

Page4::~Page4(){
    
}

bool Page4::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    tools->addTouchEff(this);
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = tools->blueLabel("こむぎことふくらしこをふるって入れよう", 28,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 
                                                 auto label = static_cast<MenuItemLabel*>(ref);
                                                 label->setString("Sift the flour and baking powder");
                                                 label->setScale(1.3);
                                                 
                                                 tools->playSound(Tools::sound::P4);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabelMenu, 2);
    
    
    auto actPhoto = Sprite::create("CupcakeMake3.png");
    actPhoto->setTag(10);
    actPhoto->setOpacity(0);
    actPhoto->setScale(1.3);
    actPhoto->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    this->addChild(actPhoto);
    
    
    
    auto photo = MenuItemImage::create("CupcakeMake3.png","CupcakeMake3.png",
                                       [&](Ref* ref){
                                           
                                           auto myImg = static_cast<MenuItemImage*>(ref);
                                           myImg->setOpacity(0);
                                           
                                           auto actImg = static_cast<Sprite*>(getChildByTag(10));
                                           actImg->setOpacity(255);
                                           actImg->runAction(RotateBy::create(0.2, 0, 180));
                                           
                                           tools->playSoundSet(_tapNum, "C");
                                           
                                           if(_tapNum > 2){
                                               _tapNum = 0;
                                           }else{
                                               _tapNum++;
                                           }

                                           
                                       });
    
    photo->setScale(1.3);
    photo->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    
    auto photoMenu = Menu::create(photo, NULL);
    photoMenu->setPosition(0, 0);
    this->addChild(photoMenu);
    
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);

                                          auto scene = Page5::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);

                                          auto scene = Page3::createScene();
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

Scene* Page4::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page4::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}