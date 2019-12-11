#import "Storage.h"

@implementation Storage
// Implementation



-(instancetype)init:(int)meret
{
    self=[super init];
    if(self)
    {
        NSInteger my[10];
        self.meret=meret;
        self.tomb=my;
    }
    return self;
}



-(instancetype)initWitharray:(NSInteger*)array : (int)meret
{
    self = [super init];
     if (self) {
     self.tomb=array;
     }
     return self;
}





-(int)getindex:(int)index
{
return self.tomb[index];
}

-(int)mostfrequent
{
int re;
for(int i=0;i<self.meret;i++){
    
    
    
    
    int count=0;
    int selected=self.tomb[0];
for(int i=0;i<self.meret;i++){
// [] notation eould be better
    if(selected=self.tomb[i]){
        count++;
    }else
    {
        count--;
        if(count<0){
            count=0;
            selected=self.tomb[i];
        }
    }
    
}
    return selected;
    
    
    
    
    
    
}
    return 0;
}

-(int)smallest
{

int smallest=self.tomb[0];
for(int i=0;i<self.meret;i++){
    if(smallest>self.tomb[i]){
        smallest=self.tomb[i];
    }
    
}
    return smallest;
}


-(int)largest{
    int bigger=self.tomb[0];
for(int i=0;i<self.meret;i++){
    if(bigger<self.tomb[i]){
        bigger=self.tomb[i];
    }
    
}
    return bigger;
}






@end 