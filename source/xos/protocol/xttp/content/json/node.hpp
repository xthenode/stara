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
///   File: node.hpp
///
/// Author: $author$
///   Date: 7/7/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_CONTENT_JSON_NODE_HPP
#define XOS_PROTOCOL_XTTP_CONTENT_JSON_NODE_HPP

#include "xos/protocol/xttp/content/json/node_type.hpp"
#include "xos/protocol/xttp/content/json/string.hpp"
#include <sstream>
#include <list>

namespace xos {
namespace protocol {
namespace xttp {
namespace content {
namespace json {

class exported node;
typedef ::std::list<node> nodes;
typedef message::part node_extends;
typedef node_extends::implements node_implements;

/// class node
class exported node: virtual public node_implements, public node_extends {
public:
    typedef node_implements implements;
    typedef node_extends extends;
    typedef node derives;
    
    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    node(const string_t& chars): extends(chars), type_(null_node) {
    }
    node(const char_t* chars, size_t length): extends(chars, length), type_(null_node) {
    }
    node(const char_t* chars): extends(chars), type_(null_node) {
    }
    node(const node& copy): extends(copy), type_(null_node) {
    }
    node(): type_(null_node) {
    }
    virtual ~node() {
    }

    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;
        // success = this->read_this(count, c, reader);
        return success;
    }
    virtual bool write(ssize_t& count, writer_t& writer) {
        bool success = false;
        // success = this->write_this(count, writer);
        return success;
    }

    /// combine / separate
    virtual bool combine() {
        bool success = true;
        return success;
    }
    virtual bool separate() {
        bool success = true;
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        return *this;
    }
    virtual derives& set_defaults() {
        string_.clear();
        return *this;
    }

protected:
     node_type type_;
     json::string string_;
}; /// class node

} /// namespace json
} /// namespace content
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_CONTENT_JSON_NODE_HPP 
