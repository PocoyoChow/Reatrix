//
//  ViewController.mm
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#import "ViewController.h"
#import "ReatrixMac.h"
#include "DemoSystem.h"
#include "World.h"

@interface ViewController()
{
    ReatrixMac *_rtx;
}
@end

@implementation ViewController

NAMESPACE_REATRIX_ENGINE_USING

- (void)loadView
{
    NSWindow *window = [[NSApplication sharedApplication] keyWindow];
    CGSize size = [window contentRectForFrameRect:window.contentLayoutRect].size;
    _rtx = [[ReatrixMac alloc] initWithFrame:NSMakeRect(0, 0, size.width, size.height)];
    SharedPtr<World> world = World::create("test");
    SharedPtr<DemoSystem> system = MakeShared<DemoSystem>();
    world->addSystem(system);
    [_rtx loadWorld:world];
    self.view = _rtx.view;
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
