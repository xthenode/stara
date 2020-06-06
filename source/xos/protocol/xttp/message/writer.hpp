///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: writer.hpp
///
/// Author: $author$
///   Date: 5/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_MESSAGE_WRITER_HPP
#define XOS_PROTOCOL_XTTP_MESSAGE_WRITER_HPP

#include "xos/protocol/xttp/message/part.hpp"
#include "xos/io/string/writer.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {

/// class writert
template 
<class TPart = part, class TWriter = typename TPart::writer_t,
 class TExtends = io::string::writert<TWriter>, class TImplements = typename TExtends::implements>
class exported writert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef writert derives;

    typedef TPart part_t;
    
    /// constructor / destructor
    writert(const writert& copy): extends(copy) {
    }
    writert(part_t& part): extends(part) {
    }
    virtual ~writert() {
    }
}; /// class writert
typedef writert<> writer;

} /// namespace message
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_MESSAGE_WRITER_HPP 
