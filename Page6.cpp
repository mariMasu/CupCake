//
//  Page6.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Page6.hpp"

#include "CupcakeTitle.hpp"
#include "Page5.hpp"
#include "Tools.hpp"

#include "audio/include/SimpleAudioEngine.h"


USING_NS_CC;


Page6::Page6(){
    
}

Page6::~Page6(){
    
}

bool Page6::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = Label::createWithSystemFont("Decorate!", "Marker Felt", 47);
    
    titleLabel->setColor(Color3B(0,160,210));
    titleLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    titleLabel->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabel, 2,10);
    
    
    
    auto titleLabel2 = Label::createWithSystemFont("Congratulations!", "Marker Felt", 60);
    
    titleLabel2->setColor(Color3B(0,160,210));
    titleLabel2->enableOutline(Color4B(0, 160, 210, 255),5);
    titleLabel2->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    titleLabel2->setOpacity(0);
    this->addChild(titleLabel2, 2,11);
    
    
    auto photo2 = MenuItemImage::create("CupcakeMake9.png","CupcakeMake9.png",
                                       [](Ref* ref){
                                           CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                           
                                       });
    
    photo2->setScale(1.2);
    photo2->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    
    auto photo = MenuItemImage::create("CupcakeMake8.png","CupcakeMake8.png",
                                       [this](Ref *pSender){
                                           auto sender = (MenuItemImage *)pSender;
                                           CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("shrink1.mp3");
                                           
                                           auto rotate = RotateTo::create(0.8,900);
                                           auto scale = ScaleBy::create(0.8, 0);
                                           
                                           auto spawn = Spawn::create(rotate,scale, NULL);
                                           
                                           auto callback = CallFuncN::create([](Ref *sender){
                                               
                                               ((MenuItemImage *)sender)->removeFromParent();
                                           });
                                           
                                           auto callback2 = CallFuncN::create([this](Ref *sender){
                                               
                                               CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision21.mp3");
                                               
                                               auto label = (Label*)(this->getChildByTag(10));
                                               
                                               auto fadeOutAction = FadeOut::create(0.5);
                                               auto fadeIn = FadeIn::create(0.5);
                                               label->runAction(fadeOutAction);
                                               
                                               auto label2 = (Label*)(this->getChildByTag(11));
                                               label2->runAction(fadeIn);
                                               
                                               
                                               
                                               
                                           });
                                           
                                           auto callback3 = CallFuncN::create([this](Ref *sender){
                                               
                                               auto winSize = Director::getInstance()->getWinSize();
                                               
                                               
                                               auto title = MenuItemImage::create("CupcakeTitle.png","CupcakeTitlePress.png",
                                                                                  [](Ref* ref){
                                                                                      CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                                                                      auto scene = CupcakeTitle::createScene();
                                                                                      auto transition = TransitionPageTurn::create(1.2, scene,false);
                                                                                      Director::getInstance()->replaceScene(transition);
                                                                                  });
                                               
                                               
                                               title->setScale(0.8);
                                               title->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
                                               
                                               auto titleButton = Menu::create(title,NULL);
                                               titleButton->setPosition(0, 0);
                                               titleButton->setTag(12);
                                               this->addChild(titleButton);
                                               
                                               
                                           });
                                           
                                           auto seq = Sequence::create(spawn,callback,callback2,callback3,NULL);
                                           
                                           sender->runAction(seq);
                                           });
    
    
    photo->setScale(1.2);
    photo->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    
    auto photoMenu = Menu::create(photo2,photo,NULL);
    photoMenu->setPosition(0,0);
    this->addChild(photoMenu);
    
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                          auto scene = Page5::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,true);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    back->setScale(0.8);
    back->setPosition(Vec2(winSize.width / 2 * 0.2, winSize.height / 1.1));
    
    
    auto Button = Menu::create(back, NULL);
    Button->setPosition(0, 0);
    this->addChild(Button);
    
    
    
    return true;
}

Scene* Page6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page6::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}