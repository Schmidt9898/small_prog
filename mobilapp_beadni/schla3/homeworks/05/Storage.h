#import <Foundation/Foundation.h>

@interface Storage : NSObject
// Public declarations
//@property (nonatomic) NSInteger *array;
//???
@property (nonatomic) NSInteger *tomb;
@property (nonatomic) int meret;



-(instancetype)init:(int)meret;
-(instancetype)initWitharray:(NSInteger*)array : (int)meret;
-(int)getindex:(int)index;
-(int)mostfrequent;
-(int)smallest;
-(int)largest;
@end