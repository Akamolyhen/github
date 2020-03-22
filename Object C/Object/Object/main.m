//
//  main.m
//  Object
//
//  Created by 恶龙咆哮 on 2020/3/20.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

/*#import <Foundation/Foundation.h>

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
*/
/*#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello,Objective-C!");
        
    }
    return 0;
}
*/


/*BOOL areIntsDifferent(int thing1,int thing2){
    if(thing1==thing2){
        return NO;}
    else{
        return YES;}
}


NSString *boolString (BOOL yesNO)
{
    if(yesNO==NO){
        return(@"NO");
    }
    else{
        return (@"YES");}
}

int main(){
    BOOL areTheyDifferent;
    areTheyDifferent=areIntsDifferent(5, 5);
    NSLog(@"are %d and %d different? %@",5,5,boolString(areTheyDifferent));
    areTheyDifferent=areIntsDifferent(23, 45);
    NSLog(@"are %d and %d different? %@",23,45,boolString(areTheyDifferent));
    return 0;
    
}*/
#define NSLog(FORMAT, ...) printf("%s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String])
#import <Foundation/Foundation.h>

// --------------------------------------------------
// constants for the different kinds of shapes and their colors

typedef enum {
    kRedColor,
    kGreenColor,
    kBlueColor
} ShapeColor;


// --------------------------------------------------
// Shape bounding rectangle


typedef struct {
    int x, y, width, height;
} ShapeRect;


// --------------------------------------------------
// convert from the ShapeColor enum value to a human-readable name

NSString *colorName (ShapeColor color)
{
    switch (color) {
        case kRedColor:
            return @"red";
            break;
        case kGreenColor:
            return @"green";
            break;
        case kBlueColor:
            return @"blue";
            break;
    }
    
    return @"no color";
    
} // colorName

@interface Shape : NSObject
{
    ShapeColor    fillColor;
    ShapeRect    bounds;
}
- (void) setFillColor: (ShapeColor) fillColor;

- (void) setBounds: (ShapeRect) bounds;

- (void) draw;
    

@end

@implementation Shape

- (void) setFillColor: (ShapeColor) c
{
    fillColor = c;
} // setFillColor


- (void) setBounds: (ShapeRect) b
{
    bounds = b;
} // setBounds


- (void) draw
{
    
} // draw

@end
// --------------------------------------------------
// All about Circles

@interface Circle :Shape


@end // Circle


@implementation Circle


- (void) draw
{
    NSLog (@"drawing a circle at (%d %d %d %d) in %@",
           bounds.x, bounds.y,
           bounds.width, bounds.height,
           colorName(fillColor));
} // draw

@end // Circle




// --------------------------------------------------
// All about Rectangles

@interface Rectangle : Shape


@end // Rectangle


@implementation Rectangle



- (void) draw
{
    NSLog (@"drawing a rectangle at (%d %d %d %d) in %@",
           bounds.x, bounds.y,
           bounds.width, bounds.height,
           colorName(fillColor));
} // draw

@end // Rectangle


// --------------------------------------------------
// All about OblateSphereoids

@interface OblateSphereoid : Shape

@end // OblateSphereoid


@implementation OblateSphereoid




- (void) draw
{
    NSLog (@"drawing an egg at (%d %d %d %d) in %@",
           bounds.x, bounds.y,
           bounds.width, bounds.height,
           colorName(fillColor));
} // draw

@end // OblateSphereoid



// --------------------------------------------------
// All about Triangles

@interface Triangle : Shape

@end // Triangle


@implementation Triangle




- (void) draw
{
    NSLog (@"drawing a triangle at (%d %d %d %d) in %@",
           bounds.x, bounds.y,
           bounds.width, bounds.height,
           colorName(fillColor));
} // draw

@end // Triangle

@interface RoundedRectangle : Shape
{
    int radius;
}

@end
// --------------------------------------------------
// Draw the shapes

void drawShapes (id shapes[], int count)
{
    int i;
    
    for (i = 0; i < count; i++) {
        id shape = shapes[i];
        [shape draw];
    }
    
} // drawShapes



// --------------------------------------------------
// The main function.  Make the shapes and draw them

int main (int argc, const char * argv[])
{
    id shapes[4];
    
    ShapeRect rect0 = { 0, 0, 10, 30 };
    shapes[0] = [Circle new];
    [shapes[0] setBounds: rect0];
    [shapes[0] setFillColor: kRedColor];
    
    ShapeRect rect1 = { 30, 40, 50, 60 };
    shapes[1] = [Rectangle new];
    [shapes[1] setBounds: rect1];
    [shapes[1] setFillColor: kGreenColor];
    
    ShapeRect rect2 = { 15, 19, 37, 29 };
    shapes[2] = [OblateSphereoid new];
    [shapes[2] setBounds: rect2];
    [shapes[2] setFillColor: kBlueColor];

    ShapeRect rect3 = { 47, 32, 80, 50 };
    shapes[3] = [Triangle new];
    [shapes[3] setBounds: rect3];
    [shapes[3] setFillColor: kRedColor];
    
    drawShapes (shapes, 4);
    
    return (0);
    
} // main

