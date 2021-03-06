//
//  ReatrixMac.h
//  ReatrixDemo
//
//  Created by Lyn Chow on 2019/5/29.
//  Copyright © 2019 Lyn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#include "World.h"

NS_ASSUME_NONNULL_BEGIN

@interface ReatrixMac : NSObject
- (instancetype)initWithFrame:(NSRect)frameRect;
- (NSView *)view;
- (BOOL)loadWorld:(SharedPtr<rtx::World>)world;
- (void)destroy;
@end

NS_ASSUME_NONNULL_END
