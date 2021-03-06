/*
 * Tencent is pleased to support the open source community by making wwsearch
 * available.
 *
 * Copyright (C) 2018-present Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#pragma once

#include "or_iterator.h"
#include "prefix_query.h"
#include "weight.h"

namespace wwsearch {

class PrefixWeight : public Weight {
 private:
  // because we must store values.so put it here.
  std::vector<std::string> values_;
  std::vector<DocListReaderCodec *> iterators;
  OrIterator *or_iterator;
  Codec *codec_;  // outer reference.

 public:
  PrefixWeight(PrefixQuery *query);

  virtual ~PrefixWeight();

  virtual Scorer *GetScorer(SearchContext *context);

  virtual BulkScorer *GetBulkScorer(SearchContext *context);

 private:
};

}  // namespace wwsearch
