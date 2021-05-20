%########################################################################
%# Copyright (c) 1988-2020 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: main-process_request_to-hxx.t
%#
%# Author: $author$
%#   Date: 7/18/2020
%########################################################################
%with(%
%is_include_path,%(%else-then(%is_include_path%,%(%is_Include_path%)%)%)%,%
%include_path,%(%else-then(%if-no(%is_include_path%,,%(%include_path%)%)%,%(%if-no(%is_include_path%,,%(%filepath(%input%)%/../../../../protocol/http/request/method)%)%)%)%)%,%
%Include_path,%(%else-then(%if-no(%is_include_path%,,%(%Include_path%)%)%,%(%if-no(%is_include_path%,,%(%include_path%)%)%)%)%)%,%
%INCLUDE_PATH,%(%else-then(%INCLUDE_PATH%,%(%toupper(%Include_path%)%)%)%)%,%
%include_path,%(%else-then(%_include_path%,%(%tolower(%Include_path%)%)%)%)%,%
%is_which,%(%else-then(%is_which%,%(%is_Which%)%)%)%,%
%which,%(%else-then(%if-no(%is_which%,,%(%which%)%)%,%(%if-no(%is_which%,,%(%include(%Include_path%/which.t)%)%)%)%)%)%,%
%Which,%(%else-then(%if-no(%is_which%,,%(%Which%)%)%,%(%if-no(%is_which%,,%(%which%)%)%)%)%)%,%
%WHICH,%(%else-then(%WHICH%,%(%toupper(%Which%)%)%)%)%,%
%which,%(%else-then(%_which%,%(%tolower(%Which%)%)%)%)%,%
%%(%
%%parse(%Which%,%(,)%,,,,%(
    /// ...process_request_to_%Which%
    virtual int process_request_to_%Which%(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = this->all_process_request_%if(%equal(unknown,%Which%)%,default,to_unknown)%(request, reader, argc, argv, env);
        return err;
    }
    virtual int before_process_request_to_%Which%(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_to_%Which%(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_to_%Which%(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_request_to_%Which%(request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_request_to_%Which%(request, reader, argc, argv, env);
            if ((err2 = after_process_request_to_%Which%(request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
)%,Which)%%
%
    /// ...process_request_default
    virtual int process_request_default(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_request_default(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_default(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_default(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_request_default(request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_request_default(request, reader, argc, argv, env);
            if ((err2 = after_process_request_default(request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_request...
    virtual int process_request(request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        switch (request.line().method().which()) {%parse(%Which%,%(,)%,,,,%(%with(which,%(%tolower(%Which%)%)%,%(
        case xos::protocol::http::request::method::%Which%:
            err = this->all_process_request_to_%Which%(request, reader, argc, argv, env);
            break;)%)%)%,Which)%
        default:
            err = this->all_process_request_to_unknown(request, reader, argc, argv, env);
            break;
        } /// switch
        return err;
    }
%
%)%)%