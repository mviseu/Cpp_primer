#include "QueryPtr.h"
#include "BaseQueryPtr.h"
#include "NotQueryPtr.h"
#include "AndQueryPtr.h"
#include "OrQueryPtr.h"

#include <memory>

QueryPtr operator~(const QueryPtr &qr) {
	BaseQueryPtr * ptr = new NotQueryPtr(qr);
	return ptr;
}

QueryPtr operator&(const QueryPtr &lhs, const QueryPtr &rhs) {
	BaseQueryPtr * ptr = new AndQueryPtr(lhs, rhs);
	return ptr;
}

QueryPtr operator|(const QueryPtr &lhs, const QueryPtr &rhs) {
	BaseQueryPtr * ptr = new OrQueryPtr(lhs, rhs);
	return ptr;
}

std::ostream &operator<<(std::ostream &os, const QueryPtr &q) {
	return os << q.rep();
}