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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 6/14/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_PROTOCOL_IDENTIFIER_HPP
#define XOS_PROTOCOL_HTTP_PROTOCOL_IDENTIFIER_HPP

#include "xos/protocol/xttp/protocol/identifier.hpp"
#include "xos/protocol/http/protocol/name.hpp"
#include "xos/protocol/http/protocol/version.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace protocol {

/// class identifiert
template 
<class TExtends = xttp::protocol::extended::identifiert
 <http::protocol::name, http::protocol::version>, 
 class TImplements = typename TExtends::implements>
class exported identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef identifiert derives;

    typedef typename extends::name_t name_t;
    typedef typename extends::version_t version_t;
    typedef typename extends::part_t part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    identifiert(const name_t& name, const version_t& version): extends(name, version)  {
        this->combine();
    }
    identifiert(const string_t& name, const string_t& version): extends(name, version)  {
        this->combine();
    }
    identifiert(const char_t* name, const char_t* version): extends(name, version)  {
        this->combine();
    }
    identifiert(const string_t& chars): extends(chars)  {
        this->separate();
    }
    identifiert(const char_t* chars, size_t length): extends(chars, length)  {
        this->separate();
    }
    identifiert(const char_t* chars): extends(chars)  {
        this->separate();
    }
    identifiert(const identifiert& copy): extends(copy) {
    }
    identifiert() {
        this->set_default();
    }
    virtual ~identifiert() {
    }
}; /// class identifiert
typedef identifiert<> identifier;

} /// namespace protocol
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_PROTOCOL_IDENTIFIER_HPP 
