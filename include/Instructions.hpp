#pragma once
#include "Operators.hpp"
#include "Operands.hpp"

#define MOVAIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::Immediate>())
#define MOVBIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::Immediate>())
#define MOVXIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterX>(), std::make_shared<td4::Immediate>())
#define MOVYIM std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterY>(), std::make_shared<td4::Immediate>())
#define MOVAB  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define MOVBA  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::RegisterA>())
#define MOVXA  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterX>(), std::make_shared<td4::RegisterA>())
#define MOVYA  std::make_shared<td4::OperatorMov>(std::make_shared<td4::RegisterY>(), std::make_shared<td4::RegisterA>())

#define ADDAIM std::make_shared<td4::OperatorAdd>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::Immediate>())
#define ADDBIM std::make_shared<td4::OperatorAdd>(std::make_shared<td4::RegisterB>(), std::make_shared<td4::Immediate>())
#define ADDAB  std::make_shared<td4::OperatorAdd>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define SUBAB  std::make_shared<td4::OperatorSub>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define ANDAB  std::make_shared<td4::OperatorAnd>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define XORAB  std::make_shared<td4::OperatorXor>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())
#define ORAB   std::make_shared<td4::OperatorOr>(std::make_shared<td4::RegisterA>(), std::make_shared<td4::RegisterB>())

#define JMPIM  std::make_shared<td4::OperatorJmp>(std::make_shared<td4::Immediate>())
#define JNCIM  std::make_shared<td4::OperatorJnc>(std::make_shared<td4::Immediate>())
#define JZIM   std::make_shared<td4::OperatorJz>(std::make_shared<td4::Immediate>())
#define JMPXY  std::make_shared<td4::OperatorJmp>(std::make_shared<td4::RegisterXY>())

#define NEGA   std::make_shared<td4::OperatorNeg>(std::make_shared<td4::RegisterA>())
#define NOTA   std::make_shared<td4::OperatorNot>(std::make_shared<td4::RegisterA>())

#define OUTIM  std::make_shared<td4::OperatorOut>(std::make_shared<td4::Immediate>())
#define OUTB   std::make_shared<td4::OperatorOut>(std::make_shared<td4::RegisterB>())
#define OUTA   std::make_shared<td4::OperatorOut>(std::make_shared<td4::RegisterA>())
#define INA    std::make_shared<td4::OperatorIn>(std::make_shared<td4::RegisterA>())
#define INB    std::make_shared<td4::OperatorIn>(std::make_shared<td4::RegisterB>())
#define LDA    std::make_shared<td4::OperatorLd>(std::make_shared<td4::RegisterA>())
#define LDB    std::make_shared<td4::OperatorLd>(std::make_shared<td4::RegisterB>())
#define STA    std::make_shared<td4::OperatorSt>(std::make_shared<td4::RegisterA>())
#define STB    std::make_shared<td4::OperatorSt>(std::make_shared<td4::RegisterB>())
#define INCXY  std::make_shared<td4::OperatorInc>(std::make_shared<td4::RegisterXY>())
