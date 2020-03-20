//
//  main.m
//  Object
//
//  Created by 恶龙咆哮 on 2020/3/20.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Fraction : NSObject

-(void) print;
-(void) setNumber:(int) n;
-(void) setDenominator:(int) d;

@end

@implementation Fraction
{
int numerator;
int denominator;
}

-(void) print{
    NSLog(@"%i/%i",numerator,denominator);
}

-(void) setNumber:(int)n{
    numerator=n;
}
-(void) setDenominator:(int)d{
    denominator=d;
}
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        Fraction *myFraction;
        myFraction=[Fraction alloc];
        myFraction=[myFraction init];
        [myFraction setNumber:1];
        [myFraction setDenominator:3];
        NSLog(@"The value of myFraction is:");
        [myFraction print];
    }
    return 0;
}
