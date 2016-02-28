//
//  Page1.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#include "Page1.hpp"

#include "CupcakeTitle.hpp"


USING_NS_CC;


Page1::Page1(){
    
}

Page1::~Page1(){
    
}

bool Page1::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    auto background = Sprite::create("CupcakeBackground.png");
    background->setPosition(Vec2(winSize.width / 2.0, winSize.height / 2.0));
    this->addChild(background);
    
    
    auto titleFrame = Sprite::create("CupcakeFrame.png");
    titleFrame->setScale(0.5, 0.3);
    titleFrame->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleFrame);
    
    
    auto titleLabel = Label::createWithSystemFont("Ingredient", "Marker Felt", 70);
    
    titleLabel->setColor(Color3B(0,160,210));
    titleLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    titleLabel->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabel, 2);
    
    
    
    auto milk = Sprite::create("CupcakeMilk.png");
    milk->setScale(0.6);
    milk->setRotation(5.75);
    milk->setPosition(Vec2(winSize.width * 0.3065, winSize.height * 0.5640));
    milk->setTag(1);
    addChild(milk);
    
    
    
    auto egg = Sprite::create("CupcakeEgg.png");
    egg->setScale(0.6);
    egg->setRotation(-4.53);
    egg->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581));
    egg->setTag(5);
    addChild(egg);
    
    
    
    //イベントリスナーを作成
    auto listener = EventListenerTouchOneByOne::create();
    
    
    
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                       [](Ref* ref){
                                           auto scene = CupcakeTitle::createScene();
                                           auto transition = TransitionPageTurn::create(1.5, scene,false);
                                           Director::getInstance()->replaceScene(transition);
                                       });
    next->setScale(0.8);
    auto nextMenu = Menu::create(next, NULL);
    nextMenu->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    this->addChild(nextMenu);
    
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [](Ref* ref){
                                          auto scene = CupcakeTitle::createScene();
                                          auto transition = TransitionPageTurn::create(1.5, scene,true);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    back->setScale(0.8);
    auto backMenu = Menu::create(back, NULL);
    backMenu->setPosition(Vec2(winSize.width / 2 * 0.2, winSize.height / 1.1));
    this->addChild(backMenu);

    
    
    return true;
}

Scene* Page1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page1::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}