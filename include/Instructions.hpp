#pragma once
#include "Operators.hpp"
#include "Operands.hpp"

#define MOVAIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::Immediate>())
#define MOVBIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::Immediate>())
#define MOVAB  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define MOVBA  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::RegisterA>())
#define ADDAIM std::make_shared<td4::OperatorAdd>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::Immediate>())
#define ADDBIM std::make_shared<td4::OperatorAdd>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::Immediate>())
#define JMPIM  std::make_shared<td4::OperatorJmp>(std::make_shared<td4::Immediate>())
#define JNCIM  std::make_shared<td4::OperatorJnc>(std::make_shared<td4::Immediate>())
#define OUTIM  std::make_shared<td4::OperatorOut>(std::make_shared<td4::Immediate>())
#define OUTB   std::make_shared<td4::OperatorOut>(std::make_shared<td4::RegisterB>())
#define INA    std::make_shared<td4::OperatorIn>(std::make_shared<td4::RegisterA>())
#define INB    std::make_shared<td4::OperatorIn>(std::make_shared<td4::RegisterB>())
