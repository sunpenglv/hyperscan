/*
 * Copyright (c) 2015-2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \file
 * \brief Large Bounded Repeat (LBR) engine build code.
 */

#ifndef NG_LBR_H
#define NG_LBR_H

#include "ue2common.h"
#include "util/alloc.h"

#include <memory>
#include <vector>

struct NFA;

namespace ue2 {

class CharReach;
class NGHolder;
class ReportManager;
struct CastleProto;
struct CompileContext;
struct Grey;

/** \brief Construct an LBR engine from the given graph \p g. */
aligned_unique_ptr<NFA>
constructLBR(const NGHolder &g,
             const std::vector<std::vector<CharReach>> &triggers,
             const CompileContext &cc, const ReportManager &rm);

/** \brief Construct an LBR engine from the given CastleProto, which should
 * contain only one repeat. */
aligned_unique_ptr<NFA>
constructLBR(const CastleProto &proto,
             const std::vector<std::vector<CharReach>> &triggers,
             const CompileContext &cc, const ReportManager &rm);

/** \brief True if graph \p g could be turned into an LBR engine. */
bool isLBR(const NGHolder &g, const Grey &grey);

} // namespace ue2

#endif // NG_LBR_H
