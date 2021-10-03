#ifndef BPRIVATE_H
#define BPRIVATE_H

#include "A.h"

class BPrivate: private A {
public:
	BPrivate();
	virtual ~BPrivate();

	void h();
protected:
private:
};

#endif // BPRIVATE_H
