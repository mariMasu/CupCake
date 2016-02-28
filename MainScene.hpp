//
//  MainScene.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"



class MainScene :public cocos2d::Layer
{
public:
    
    
    static cocos2d::Scene* createScene();
    
    MainScene();
    virtual ~MainScene();
    
    bool init() override;
    void update(float dt);
    
    CREATE_FUNC(MainScene);
    
    
private:
    
    void on();

    
};

#endif /* MainScene_hpp */
