//
//  Page5.cpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#include "Page5.hpp"

#include "Page4.hpp"

#include "Page6.hpp"

#include "Tools.hpp"

#include "audio/include/SimpleAudioEngine.h"


USING_NS_CC;


Page5::Page5(){
    
}

Page5::~Page5(){
    
}

bool Page5::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    
    auto tools = Tools::create();
    
    auto winSize = Director::getInstance()->getWinSize();
    
    tools->addTouchEff(this);
    tools->addBackGround(this);
    tools->addTitleFrame(this);
    
    
    
    auto titleLabel = tools->blueLabel("25分やきます", 45,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 
                                                 auto label = static_cast<MenuItemLabel*>(ref);
                                                 label->setString("Bake the cupcakes for 25 minutes");
                                                 label->setScale(0.8);
                                                 
                                                 tools->playSound(Tools::sound::P5);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabelMenu, 2);

    
    
    auto image4 = MenuItemImage::create("CupcakeMake7.png","CupcakeMake7.png",
                                        [&](Ref* ref){
                                            tools->playSound(Tools::sound::KIRAKI);
                                            tools->customAction(ref,1);
                                            
                                            auto winS = Director::getInstance()->getWinSize();


                                            ParticleSystemQuad* pSys;
                                            pSys = ParticleSystemQuad::create("yuge.plist");
                                            pSys->setPosition(Vec2(winS.width / 2.0, winS.height / 2));
                                            pSys->setAutoRemoveOnFinish(true);
                                            
                                            this->addChild(pSys);
                                        });
    
    image4->setScale(1.3);
    image4->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    image4->setRotation(-1.2);
    auto photo4 = Menu::create(image4,NULL);
    photo4->setPosition(0,0);
    this->addChild(photo4);
    
    
    auto image3 = MenuItemImage::create("CupcakeMake6.png","CupcakeMake6.png",
                                        [&](Ref* ref){
                                            tools->playSound(Tools::sound::D3);
                                            
                                            tools->customAction(ref,2,Director::getInstance()->getWinSize());
                                        });
    
    image3->setScale(1.3);
    image3->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    image3->setRotation(3.2);
    auto photo3 = Menu::create(image3,NULL);
    photo3->setPosition(0,0);
    this->addChild(photo3);
    
    
    
    auto image2 = MenuItemImage::create("CupcakeMake5.png","CupcakeMake5.png",
                                        [&](Ref* ref){
                                            tools->playSound(Tools::sound::D2);
                                            
                                            tools->customAction(ref,2,Director::getInstance()->getWinSize());
                                        });
    
    image2->setScale(1.3);
    image2->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    image2->setRotation(-1.5);
    auto photo2 = Menu::create(image2,NULL);
    photo2->setPosition(0,0);
    this->addChild(photo2);
    
    
    
    auto image1 = MenuItemImage::create("CupcakeMake4.png","CupcakeMake4.png",
                                        [&](Ref* ref){
                                            tools->playSound(Tools::sound::D1);
                                            
                                            tools->customAction(ref,2,Director::getInstance()->getWinSize());
                                        });
    
    
    image1->setScale(1.3);
    image1->setPosition(Vec2(winSize.width / 2, winSize.height / 2.2));
    image1->setRotation(1.6);
    auto photo1 = Menu::create(image1,NULL);
    photo1->setPosition(0,0);
    this->addChild(photo1);
    
    
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
                                          auto scene = Page6::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
                                          auto scene = Page4::createScene();
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

Scene* Page5::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Page5::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}