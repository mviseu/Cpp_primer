#include "Query.h"
#include "BaseQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

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