//
//  Tools.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>

#include "cocos2d.h"

class Tools : public cocos2d::Layer
{
    
    cocos2d::Size _winSize;
    
public:
    
    enum class sound
    {
        TAP1,
        TAP2,
        TAP3,
        BOYON,
        KURUN,
        MILK,
        BUTTER,
        SUGAR,
        BAKINGP,
        FLOUR,
        EGG,
        P0,
        P1,
        P2,
        P3,
        P4,
        P5,
        P6
        
    };
    
    Tools();
    
    virtual ~Tools();
    
    virtual bool init();
    
    CREATE_FUNC(Tools);
    
    void addBackGround(Layer *layer);
    
    void addTitleFrame(Layer *layer);
    
    void addNext(Layer *layer,int tag);
    
    void addBack(Layer *layer,int tag);
    
    cocos2d::Label *blueLabel(std::string str,int size,bool dark);
    
    void playSound(enum sound kind);
    
    void customAction(cocos2d::Ref *item,int nam);
    
};


#endif /* Tools_hpp */
