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
    Tools();
    
    virtual ~Tools();
    
    virtual bool init();
    
    CREATE_FUNC(Tools);
    
    void addBackGround(Layer *layer);
    
    void addTitleFrame(Layer *layer);
    
    void addNext(Layer *layer,int tag);
    
    void addBack(Layer *layer,int tag);
    
    cocos2d::Scene* createNextBackScean(int swi);
    
};


#endif /* Tools_hpp */
