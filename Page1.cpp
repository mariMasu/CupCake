//
//  Page1.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#include "Page1.hpp"

#include "CupcakeTitle.hpp"
#include "Page2.hpp"
#include "ModalLayer.hpp"
#include "Tools.hpp"

#include "audio/include/SimpleAudioEngine.h"



USING_NS_CC;


Page1::Page1(){

    
}

Page1::~Page1(){
    
}

bool Page1::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    auto titleLabel = Label::createWithSystemFont("Ingredient", "Marker Felt", 70);
    
    titleLabel->setColor(Color3B(0,160,210));
    titleLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    titleLabel->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabel, 2);
    
    
    
    
    int p = 40;
    
    auto milkLabel = Label::createWithSystemFont("Milk", "Marker Felt", 40);
    milkLabel->setColor(Color3B(255,255,255));
    milkLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    milkLabel->setRotation(5.75);
    milkLabel->setPosition(Vec2(winSize.width * 0.3065, winSize.height * 0.5640+p));
    milkLabel->setOpacity(0);
    this->addChild(milkLabel,5,10);
    
    
    
    auto butterLabel = Label::createWithSystemFont("Butter", "Marker Felt", 40);
    butterLabel->setColor(Color3B(255,255,255));
    butterLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    butterLabel->setRotation(-3.08);
    butterLabel->setPosition(Vec2(winSize.width * 0.6672, winSize.height * 0.569+p));
    butterLabel->setOpacity(0);
    this->addChild(butterLabel,5,11);
    
    auto flourLabel = Label::createWithSystemFont("Flour", "Marker Felt", 40);
    flourLabel->setColor(Color3B(255,255,255));
    flourLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    flourLabel->setRotation(-4.52);
    flourLabel->setPosition(Vec2(winSize.width * 0.1640, winSize.height * 0.2386+p));
    flourLabel->setOpacity(0);
    this->addChild(flourLabel,5,12);
    
    
    auto bakingPLabel = Label::createWithSystemFont("Baking Powder", "Marker Felt", 40);
    bakingPLabel->setColor(Color3B(255,255,255));
    bakingPLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    bakingPLabel->setRotation(1.57);
    bakingPLabel->setPosition(Vec2(winSize.width * 0.4902, winSize.height * 0.2235+p));
    bakingPLabel->setOpacity(0);
    this->addChild(bakingPLabel,5,13);
    
    auto eggLabel = Label::createWithSystemFont("Egg", "Marker Felt", 40);
    eggLabel->setColor(Color3B(255,255,255));
    eggLabel->enableOutline(Color4B(0, 160, 210, 255),5);
    eggLabel->setRotation(-4.53);
    eggLabel->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581+p));
    eggLabel->setOpacity(0);
    this->addChild(eggLabel,5,14);
    
    auto milk = MenuItemImage::create("CupcakeMilk.png","CupcakeMilk.png",
                                      [this](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                          
                                          auto label = (Label*)this->getChildByTag(10);
                                          label->runAction(FadeIn::create(0.3));
                                      });
    milk->setScale(0.6);
    milk->setRotation(5.75);
    milk->setPosition(Vec2(winSize.width * 0.3065, winSize.height * 0.5640+p));
    milk->setTag(1);
    
    auto butter = MenuItemImage::create("CupcakeButter.png","CupcakeButter.png",
                                      [this](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                          
                                          auto label = (Label*)this->getChildByTag(11);
                                          label->runAction(FadeIn::create(0.3));
                                      });
    butter->setScale(0.6);
    butter->setRotation(-3.08);
    butter->setPosition(Vec2(winSize.width * 0.6672, winSize.height * 0.569+p));
    butter->setTag(2);
    
    auto flour = MenuItemImage::create("CupcakeFlour.png","CupcakeFlour.png",
                                        [this](Ref* ref){//auto moda = ModalWindow::create();
                                            CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                            
                                            auto label = (Label*)this->getChildByTag(12);
                                            label->runAction(FadeIn::create(0.3));
                                        });
    flour->setScale(0.6);
    flour->setRotation(-4.52);
    flour->setPosition(Vec2(winSize.width * 0.1640, winSize.height * 0.2386+p));
    flour->setTag(3);
    
    auto bakingP = MenuItemImage::create("CupcakeBakingP.png","CupcakeBakingP",
                                     [this](Ref* ref){
                                         CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                         
                                         auto label = (Label*)this->getChildByTag(13);
                                         label->runAction(FadeIn::create(0.3));
                                     });
    bakingP->setScale(0.6);
    bakingP->setRotation(1.57);
    bakingP->setPosition(Vec2(winSize.width * 0.4902, winSize.height * 0.2235+p));
    bakingP->setTag(4);
    
    auto egg = MenuItemImage::create("CupcakeEgg.png","CupcakeEgg",
                              [this](Ref* ref){
                                  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision4.mp3");
                                  
                                  auto label = (Label*)this->getChildByTag(14);
                                  label->runAction(FadeIn::create(0.3));
                              });
    egg->setScale(0.6);
    egg->setRotation(-4.53);
    egg->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581+p));
    egg->setTag(5);
    
    
    
    auto ingredient = Menu::create(milk,butter,flour,bakingP,egg,NULL);
    ingredient->setPosition(0, 0);
    this->addChild(ingredient);
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                          auto scene = Page2::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [](Ref* ref){
                                          CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("decision3.mp3");
                                          auto scene = CupcakeTitle::createScene();
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