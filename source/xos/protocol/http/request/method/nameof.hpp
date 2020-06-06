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
///   File: nameof.hpp
///
/// Author: $author$
///   Date: 5/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAMEOF_HPP
#define XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAMEOF_HPP

#include "xos/protocol/http/request/method/name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace request {
namespace method {
namespace nameof {

/// class GET
class exported GET: public method::name {
public:
    typedef method::name extends;
    typedef name derives;
    /// constructor / destructor
    GET(const GET& copy): extends(copy) {}
    GET(): extends(method::GET) {}
    virtual ~GET() {}
}; /// class GET

/// class POST
class exported POST: public method::name {
public:
    typedef method::name extends;
    typedef name derives;
    /// constructor / destructor
    POST(const POST& copy): extends(copy) {}
    POST(): extends(method::POST) {}
    virtual ~POST() {}
}; /// class POST

} /// namespace nameof
} /// namespace method
} /// namespace request
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_REQUEST_METHOD_NAMEOF_HPP 
