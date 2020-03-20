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
-(void) setDenominator:(int) d;//-（）告诉编译器这是一种实例方法
-(int) numerator;
-(int) denominator;
@end

@implementation Fraction
{
    int numerator;
    int denominator;
}
-(int)  numerator{
    return numerator;
}
-(int)  denominator{
    return denominator;
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
        Fraction *myFraction,*myFraction1;
        myFraction=[Fraction alloc];
        myFraction=[myFraction init];
        //myFraction=[[Fraction alloc]init];
        myFraction1=[Fraction alloc];
        myFraction1=[myFraction1 init];
        [myFraction setNumber:1];
        [myFraction setDenominator:3];
        [myFraction1 setNumber:2];
        [myFraction1 setDenominator:3];
        NSLog(@"The value of myFraction is:%i/%i",[myFraction numerator],[myFraction denominator]);
        [myFraction print];
        NSLog(@"The value of myFraction1 is:");
        [myFraction1 print];
    }
    return 0;
}
