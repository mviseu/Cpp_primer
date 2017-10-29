#include "Query.h"
#include "BaseQuery.h"
#include "NotQuery.h"

#include <memory>

Query operator~(const Query &qr) {
	return std::shared_ptr<BaseQuery>(new NotQuery(qr));
}