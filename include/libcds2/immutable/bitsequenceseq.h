/********************************************************************************
Copyright (c) 2012, Francisco Claude.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    * Neither the name of libcds nor the names of its
      contributors may be used to endorse or promote products derived from this
      software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

********************************************************************************/


#ifndef SRC_IMMUTABLE_BITSEQUENCESEQ_H_
#define SRC_IMMUTABLE_BITSEQUENCESEQ_H_


#include <libcds2/libcds.h>
#include <libcds2/io.h>
#include <libcds2/array.h>
#include <libcds2/immutable/bitsequence.h>


#include <fstream>

namespace cds {
namespace immutable {

using cds::basic::cds_word;
using cds::basic::Array;
using std::istream;
using std::ostream;

/** Base class for static bitsequences, contains many abstract functions,
 *  so this can't be instantiated. It includes base implementations for
 *  rank0, select0 and select1 based on rank0.
 *
 *  @author Francisco Claude
 */
class BitSequenceSeq : public BitSequence {
  public:
    explicit BitSequenceSeq(Array *array);
    virtual ~BitSequenceSeq();
    virtual cds_word Rank0(const cds_word i) const;
    virtual cds_word Rank0(const cds_word i, bool *access) const;
    virtual cds_word Select0(const cds_word i) const;
    virtual cds_word Rank1(const cds_word i) const;
    virtual cds_word Rank1(const cds_word i, bool *access) const;
    virtual cds_word Select1(const cds_word i) const;
    virtual cds_word SelectNext1(const cds_word i) const;
    virtual cds_word SelectNext0(const cds_word i) const;
    virtual cds_word SelectPrev1(const cds_word i) const;
    virtual cds_word SelectPrev0(const cds_word i) const;
    virtual bool Access(const cds_word i) const;
    virtual cds_word GetLength() const;
    virtual cds_word CountOnes() const;
    virtual cds_word CountZeros() const;
    virtual cds_word GetSize() const;
    virtual void Save(ostream &fp) const;
    static BitSequence *Load(istream &fp);

  protected:
    Array *array_;
};
};
};

#endif  // SRC_IMMUTABLE_BITSEQUENCESEQ_H_
