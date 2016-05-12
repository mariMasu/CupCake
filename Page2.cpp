//
//  Page2.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/03.
//
//

#include "Page2.hpp"

#include "Page1.hpp"
#include "Page3.hpp"
#include "Tools.hpp"


USING_NS_CC;


Page2::Page2(){
    
}

Page2::~Page2(){
    
}

bool Page2::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    tools->addTouchEff(this);
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = tools->blueLabel("さとうとバターをまぜよう", 40,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 
                                                 auto label = static_cast<MenuItemLabel*>(ref);
                                                 label->setString("Mix the sugar and buttur");
                                                 label->setScale(1.1);
                                                 
                                                 tools->playSound(Tools::sound::P2);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabelMenu, 2);
    
    
    auto actPhoto = Sprite::create("CupcakeMake1.png");
    actPhoto->setTag(10);
    actPhoto->setOpacity(0);
    actPhoto->setScale(1.3);
    actPhoto->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    this->addChild(actPhoto);
    
    
    auto photo = MenuItemImage::create("CupcakeMake1.png","CupcakeMake1.png",
                                      [&](Ref* ref){
                                          auto myImg = static_cast<MenuItemImage*>(ref);
                                          myImg->setOpacity(0);
                                          
                                          auto actImg = static_cast<Sprite*>(getChildByTag(10));
                                          actImg->setOpacity(255);
                                          actImg->runAction(RotateBy::create(0.2, 0, 180));
                                          
                                          tools->playSoundSet(_tapNum, "A");
                                          
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
                                         tools->playSound(Tools::sound::TAP1);                                          auto scene = Page3::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
                                          auto scene = Page1::createScene();
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

Scene* Page2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page2::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}