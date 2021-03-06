/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <stx/stdtypes.h>
#include <chartsql/runtime/TableExpression.h>
#include <chartsql/runtime/defaultruntime.h>

namespace csql {

class SelectExpression : public TableExpression {
public:

  SelectExpression(
      const Vector<String>& column_names,
      Vector<ScopedPtr<ValueExpression>> select_expressions);

  void execute(
      ExecutionContext* context,
      Function<bool (int argc, const SValue* argv)> fn) override;

  Vector<String> columnNames() const override;

  size_t numColumns() const override;

protected:
  Vector<String> column_names_;
  Vector<ScopedPtr<ValueExpression>> select_exprs_;
};

}
