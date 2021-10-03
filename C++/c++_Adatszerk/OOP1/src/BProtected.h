#ifndef BPROTECTED_H
#define BPROTECTED_H

#include "A.h"

class BProtected: protected A {
public:
	BProtected();
	virtual ~BProtected();

	void h();
protected:
private:
};

#endif // BPROTECTED_H
