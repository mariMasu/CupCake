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

#include "Tools.hpp"



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
    
    
    auto titleLabel = tools->blueLabel("Ingredient", 70,true);
    
    auto titleButton = MenuItemLabel::create(titleLabel,
                                             [&](Ref* ref){
                                                 tools->playSound(Tools::sound::P1);
                                             });
    
    auto titleLabelMenu = Menu::create(titleButton,NULL);
    titleLabelMenu->setPosition(Vec2(winSize.width / 2.0, winSize.height / 1.1));
    this->addChild(titleLabelMenu, 2);
    
    
    
    
    int p = 40;
    
    auto milkLabel = tools->blueLabel("Milk", 40,false);
    milkLabel->setRotation(5.75);
    milkLabel->setPosition(Vec2(winSize.width * 0.1765, winSize.height * 0.5640+p));
    milkLabel->setOpacity(0);
    this->addChild(milkLabel,5,10);
    
    auto milkLabelJ = tools->blueLabel("ぎゅうにゅう", 40,false);
    milkLabelJ->setRotation(5.75);
    milkLabelJ->setPosition(Vec2(winSize.width * 0.1765, winSize.height * 0.5640+p));
    this->addChild(milkLabelJ,5,100);
    
    auto butterLabel = tools->blueLabel("Butter", 40,false);
    butterLabel->setRotation(-3.08);
    butterLabel->setPosition(Vec2(winSize.width * 0.4852, winSize.height * 0.569+p));
    butterLabel->setOpacity(0);
    this->addChild(butterLabel,5,11);
    
    auto butterLabelJ = tools->blueLabel("ばたー", 40,false);
    butterLabelJ->setRotation(-3.08);
    butterLabelJ->setPosition(Vec2(winSize.width * 0.4852, winSize.height * 0.569+p));
    this->addChild(butterLabelJ,5,110);
    
    auto flourLabel = tools->blueLabel("Flour", 40,false);
    flourLabel->setRotation(-4.52);
    flourLabel->setPosition(Vec2(winSize.width * 0.1640, winSize.height * 0.2386+p));
    flourLabel->setOpacity(0);
    this->addChild(flourLabel,5,12);
    
    auto flourLabelJ = tools->blueLabel("こむぎこ", 40,false);
    flourLabelJ->setRotation(-4.52);
    flourLabelJ->setPosition(Vec2(winSize.width * 0.1640, winSize.height * 0.2386+p));
    this->addChild(flourLabelJ,5,120);
    
    auto bakingPLabel = tools->blueLabel("Baking Powder", 40,false);
    bakingPLabel->setRotation(1.57);
    bakingPLabel->setPosition(Vec2(winSize.width * 0.4902, winSize.height * 0.2235+p));
    bakingPLabel->setOpacity(0);
    this->addChild(bakingPLabel,5,13);
    
    auto bakingPLabelJ = tools->blueLabel("ふくらしこ", 40,false);
    bakingPLabelJ->setRotation(1.57);
    bakingPLabelJ->setPosition(Vec2(winSize.width * 0.4902, winSize.height * 0.2235+p));
    this->addChild(bakingPLabelJ,5,130);
    
    auto eggLabel = tools->blueLabel("Egg", 40,false);
    eggLabel->setRotation(-4.53);
    eggLabel->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581+p));
    eggLabel->setOpacity(0);
    this->addChild(eggLabel,5,14);
    
    auto eggLabelJ = tools->blueLabel("たまご", 40,false);
    eggLabelJ->setRotation(-4.53);
    eggLabelJ->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581+p));
    this->addChild(eggLabelJ,5,140);
    
    auto sugarLabel = tools->blueLabel("Sugar", 40,false);
    sugarLabel->setRotation(-4.53);
    sugarLabel->setPosition(Vec2(winSize.width * 0.7984, winSize.height * 0.5781+p));
    sugarLabel->setOpacity(0);
    this->addChild(sugarLabel,6,15);
    
    auto sugarLabelJ = tools->blueLabel("さとう", 40,false);
    sugarLabelJ->setRotation(-4.53);
    sugarLabelJ->setPosition(Vec2(winSize.width * 0.7984, winSize.height * 0.5781+p));
    this->addChild(sugarLabelJ,6,150);
    
    
    auto milk = MenuItemImage::create("CupcakeMilk.png","CupcakeMilk.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::MILK);
                                          
                                          auto labelJ = (Label*)this->getChildByTag(100);
                                          labelJ->runAction(FadeOut::create(0.3));
                                          
                                          auto label = (Label*)this->getChildByTag(10);
                                          label->runAction(FadeIn::create(0.3));
                                          
                                          tools->customAction(ref, 1);
                                      });
    milk->setScale(0.6);
    milk->setRotation(5.75);
    milk->setPosition(Vec2(winSize.width * 0.1765, winSize.height * 0.5640+p));
    milk->setTag(1);
    
    auto butter = MenuItemImage::create("CupcakeButter.png","CupcakeButter.png",
                                        [&](Ref* ref){
                                            tools->playSound(Tools::sound::BUTTER);
                                          
                                            auto labelJ = (Label*)this->getChildByTag(110);
                                            labelJ->runAction(FadeOut::create(0.3));
                                            
                                          auto label = (Label*)this->getChildByTag(11);
                                          label->runAction(FadeIn::create(0.3));
                                            
                                            tools->customAction(ref, 1);

                                      });
    butter->setScale(0.6);
    butter->setRotation(-3.08);
    butter->setPosition(Vec2(winSize.width * 0.4852, winSize.height * 0.569+p));
    butter->setTag(2);
    
    auto flour = MenuItemImage::create("CupcakeFlour.png","CupcakeFlour.png",
                                       [&](Ref* ref){
                                           tools->playSound(Tools::sound::FLOUR);
                                           
                                           auto labelJ = (Label*)this->getChildByTag(120);
                                           labelJ->runAction(FadeOut::create(0.3));
                                           
                                            auto label = (Label*)this->getChildByTag(12);
                                            label->runAction(FadeIn::create(0.3));
                                           
                                           tools->customAction(ref, 1);

                                        });
    flour->setScale(0.6);
    flour->setRotation(-4.52);
    flour->setPosition(Vec2(winSize.width * 0.1640, winSize.height * 0.2386+p));
    flour->setTag(3);
    
    auto bakingP = MenuItemImage::create("CupcakeBakingP.png","CupcakeBakingP",
                                         [&](Ref* ref){
                                             tools->playSound(Tools::sound::BAKINGP);
                                             
                                             auto labelJ = (Label*)this->getChildByTag(130);
                                             labelJ->runAction(FadeOut::create(0.3));
                                             
                                         auto label = (Label*)this->getChildByTag(13);
                                         label->runAction(FadeIn::create(0.3));
                                             
                                             tools->customAction(ref, 1);

                                     });
    bakingP->setScale(0.6);
    bakingP->setRotation(1.57);
    bakingP->setPosition(Vec2(winSize.width * 0.4902, winSize.height * 0.2235+p));
    bakingP->setTag(4);
    
    auto egg = MenuItemImage::create("CupcakeEgg.png","CupcakeEgg",
                                     [&](Ref* ref){
                                         tools->playSound(Tools::sound::EGG);
                                         
                                         auto labelJ = (Label*)this->getChildByTag(140);
                                         labelJ->runAction(FadeOut::create(0.3));
                                         
                                  auto label = (Label*)this->getChildByTag(14);
                                  label->runAction(FadeIn::create(0.3));
                                         
                                         tools->customAction(ref, 1);

                              });
    egg->setScale(0.6);
    egg->setRotation(-4.53);
    egg->setPosition(Vec2(winSize.width * 0.8084, winSize.height * 0.2581+p));
    egg->setTag(5);
    
    
    auto sugar = MenuItemImage::create("CupcakeSugar.png","CupcakeSugar",
                                     [&](Ref* ref){
                                         tools->playSound(Tools::sound::SUGAR);
                                         
                                         auto labelJ = (Label*)this->getChildByTag(150);
                                         labelJ->runAction(FadeOut::create(0.3));
                                         
                                         auto label = (Label*)this->getChildByTag(15);
                                         label->runAction(FadeIn::create(0.3));
                                         
                                         tools->customAction(ref, 1);

                                     });
    sugar->setScale(0.6);
    sugar->setRotation(1.53);
    sugar->setPosition(Vec2(winSize.width * 0.7984, winSize.height * 0.5781+p));
    sugar->setTag(6);
    
    
    
    auto ingredient = Menu::create(milk,butter,flour,bakingP,egg,sugar,NULL);
    ingredient->setPosition(0, 0);
    this->addChild(ingredient);
    
    
    auto next = MenuItemImage::create("CupcakeNext.png","CupcakeNextPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
                                          auto scene = Page2::createScene();
                                          auto transition = TransitionPageTurn::create(1.2, scene,false);
                                          Director::getInstance()->replaceScene(transition);
                                      });
    next->setScale(0.8);
    next->setPosition(Vec2(winSize.width / 2 * 1.8, winSize.height / 1.1));
    
    
    auto back = MenuItemImage::create("CupcakeBack.png","CupcakeBackPress.png",
                                      [&](Ref* ref){
                                          tools->playSound(Tools::sound::TAP1);
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