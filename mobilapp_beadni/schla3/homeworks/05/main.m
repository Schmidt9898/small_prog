#import <Foundation/Foundation.h>
#import "Storage.h"

int main(int argc, const char * argv[]){
       
    /* When the @autoreleasepool decorated code block complete, 
       all the temporary variables (in the code block) used memory 
       will be recycled automatically.*/
    @autoreleasepool{
        // @ means the String is a NSString type string. 
        NSLog(@"Hello World Objective-C");
    }
    
    NSInteger tomb[10];
    
    tomb[0]=1;
    tomb[1]=1;
    tomb[2]=1;
    tomb[3]=1;
    tomb[4]=2;
    tomb[5]=1;
    tomb[6]=1;
    tomb[7]=12;
    tomb[8]=6;
    tomb[9]=1;
    Storage *stor=[[Storage alloc]  initWitharray:tomb meret:10];
    
    
    
    
    
    
    
    
    return 0;
}