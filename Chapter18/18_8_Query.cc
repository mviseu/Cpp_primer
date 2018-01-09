#include "18_8_Query.h"
#include "18_8_BaseQuery.h"
#include "18_8_NotQuery.h"
#include "18_8_AndQuery.h"
#include "18_8_OrQuery.h"

#include <memory>

namespace chapter18 {

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

} // namespace chapter8