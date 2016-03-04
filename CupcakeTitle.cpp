//
//  CupcakeTitle.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#include "CupcakeTitle.hpp"
#include "audio/include/SimpleAudioEngine.h"
#include <Page1.hpp>

USING_NS_CC;


CupcakeTitle::CupcakeTitle(){
    
}

CupcakeTitle::~CupcakeTitle(){
    
}

bool CupcakeTitle::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    auto winSize = Director::getInstance()->getWinSize();
    auto background = Sprite::create("CupcakeBackground.png");
    background->setPosition(Vec2(winSize.width / 2.0, winSize.height / 2.0));
    this->addChild(background);
    
    
    auto titleFrame = Sprite::create("CupcakeFrame.png");
    titleFrame->setScale(0.8, 0.6);
    titleFrame->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.7));
    this->addChild(titleFrame);
    
    
    auto titleLabel = Label::createWithSystemFont("Making Cupcakes", "Marker Felt", 100);
    
    titleLabel->setColor(Color3B(0,160,210));
    titleLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    
    titleLabel->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.7));
    this->addChild(titleLabel, 2);

    
    auto start = MenuItemImage::create("CupcakeStart.png","CupcakeStartPress.png",
                                       [](Ref* ref){
                                           auto scene = Page1::createScene();
                                           CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");

                                           auto transition = TransitionPageTurn::create(1.5, scene,false);
                                           Director::getInstance()->replaceScene(transition);
                                           
    });
    
    
    auto menu = Menu::create(start, NULL);
    
    
    menu->setPosition(Vec2(winSize.width / 2, winSize.height / 4));
    
    this->addChild(menu);
    
    
    return true;
}

Scene* CupcakeTitle::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CupcakeTitle::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}