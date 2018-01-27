#include "19_20_Query.h"
#include "19_20_BaseQuery.h"
#include "19_20_NotQuery.h"
#include "19_20_AndQuery.h"
#include "19_20_OrQuery.h"

#include <memory>


Query operator~(const Query &qr) {
	return std::shared_ptr<BaseQuery>(new NotQuery(qr));
}

Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<BaseQuery>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<BaseQuery>(new OrQuery(lhs, rhs));
}

std::ostream &operator<<(std::ostream &os, const Query &q) {
	return os << q.rep();
}
