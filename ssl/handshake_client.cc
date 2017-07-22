/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 *
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 *
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 *
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
/* ====================================================================
 * Copyright (c) 1998-2007 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */
/* ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 *
 * Portions of the attached software ("Contribution") are developed by
 * SUN MICROSYSTEMS, INC., and are contributed to the OpenSSL project.
 *
 * The Contribution is licensed pursuant to the OpenSSL open source
 * license provided above.
 *
 * ECC cipher suite support in OpenSSL originally written by
 * Vipul Gupta and Sumit Gupta of Sun Microsystems Laboratories.
 *
 */
/* ====================================================================
 * Copyright 2005 Nokia. All rights reserved.
 *
 * The portions of the attached software ("Contribution") is developed by
 * Nokia Corporation and is licensed pursuant to the OpenSSL open source
 * license.
 *
 * The Contribution, originally written by Mika Kousa and Pasi Eronen of
 * Nokia Corporation, consists of the "PSK" (Pre-Shared Key) ciphersuites
 * support (see RFC 4279) to OpenSSL.
 *
 * No patent licenses or other rights except those expressly stated in
 * the OpenSSL open source license shall be deemed granted or received
 * expressly, by implication, estoppel, or otherwise.
 *
 * No assurances are provided by Nokia that the Contribution does not
 * infringe the patent or other intellectual property rights of any third
 * party or that the license provides you with all the necessary rights
 * to make use of the Contribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. IN
 * ADDITION TO THE DISCLAIMERS INCLUDED IN THE LICENSE, NOKIA
 * SPECIFICALLY DISCLAIMS ANY LIABILITY FOR CLAIMS BROUGHT BY YOU OR ANY
 * OTHER ENTITY BASED ON INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS OR
 * OTHERWISE.
 */

#include <openssl/ssl.h>

#include <assert.h>
#include <limits.h>
#include <string.h>

#include <utility>

#include <openssl/aead.h>
#include <openssl/bn.h>
#include <openssl/buf.h>
#include <openssl/bytestring.h>
#include <openssl/ec_key.h>
#include <openssl/ecdsa.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/mem.h>
#include <openssl/rand.h>

#include "../crypto/internal.h"
#include "internal.h"


namespace bssl {

enum ssl_client_hs_state_t {
  state_start_connect = 0,
  state_enter_early_data,
  state_read_hello_verify_request,
  state_read_server_hello,
  state_tls13,
  state_read_server_certificate,
  state_read_certificate_status,
  state_verify_server_certificate,
  state_read_server_key_exchange,
  state_read_certificate_request,
  state_read_server_hello_done,
  state_send_client_certificate,
  state_send_client_key_exchange,
  state_send_client_certificate_verify,
  state_send_client_finished,
  state_finish_flight,
  state_read_session_ticket,
  state_process_change_cipher_spec,
  state_read_server_finished,
  state_finish_client_handshake,
  state_done,
};

// ssl_get_client_disabled sets |*out_mask_a| and |*out_mask_k| to masks of
// disabled algorithms.
static void ssl_get_client_disabled(SSL *ssl, uint32_t *out_mask_a,
                                    uint32_t *out_mask_k) {
  *out_mask_a = 0;
  *out_mask_k = 0;

  // PSK requires a client callback.
  if (ssl->psk_client_callback == NULL) {
    *out_mask_a |= SSL_aPSK;
    *out_mask_k |= SSL_kPSK;
  }
}

static int ssl_write_client_cipher_list(SSL_HANDSHAKE *hs, CBB *out) {
  SSL *const ssl = hs->ssl;
  uint32_t mask_a, mask_k;
  ssl_get_client_disabled(ssl, &mask_a, &mask_k);

  CBB child;
  if (!CBB_add_u16_length_prefixed(out, &child)) {
    return 0;
  }

  // Add a fake cipher suite. See draft-davidben-tls-grease-01.
  if (ssl->ctx->grease_enabled &&
      !CBB_add_u16(&child, ssl_get_grease_value(ssl, ssl_grease_cipher))) {
    return 0;
  }

  // Add TLS 1.3 ciphers. Order ChaCha20-Poly1305 relative to AES-GCM based on
  // hardware support.
  if (hs->max_version >= TLS1_3_VERSION) {
    if (!EVP_has_aes_hardware() &&
        !CBB_add_u16(&child, TLS1_CK_CHACHA20_POLY1305_SHA256 & 0xffff)) {
      return 0;
    }
    if (!CBB_add_u16(&child, TLS1_CK_AES_128_GCM_SHA256 & 0xffff) ||
        !CBB_add_u16(&child, TLS1_CK_AES_256_GCM_SHA384 & 0xffff)) {
      return 0;
    }
    if (EVP_has_aes_hardware() &&
        !CBB_add_u16(&child, TLS1_CK_CHACHA20_POLY1305_SHA256 & 0xffff)) {
      return 0;
    }
  }

  if (hs->min_version < TLS1_3_VERSION) {
    int any_enabled = 0;
    for (const SSL_CIPHER *cipher : SSL_get_ciphers(ssl)) {
      // Skip disabled ciphers
      if ((cipher->algorithm_mkey & mask_k) ||
          (cipher->algorithm_auth & mask_a)) {
        continue;
      }
      if (SSL_CIPHER_get_min_version(cipher) > hs->max_version ||
          SSL_CIPHER_get_max_version(cipher) < hs->min_version) {
        continue;
      }
      any_enabled = 1;
      if (!CBB_add_u16(&child, ssl_cipher_get_value(cipher))) {
        return 0;
      }
    }

    // If all ciphers were disabled, return the error to the caller.
    if (!any_enabled && hs->max_version < TLS1_3_VERSION) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_NO_CIPHERS_AVAILABLE);
      return 0;
    }
  }

  // For SSLv3, the SCSV is added. Otherwise the renegotiation extension is
  // added.
  if (hs->max_version == SSL3_VERSION &&
      !ssl->s3->initial_handshake_complete) {
    if (!CBB_add_u16(&child, SSL3_CK_SCSV & 0xffff)) {
      return 0;
    }
  }

  if (ssl->mode & SSL_MODE_SEND_FALLBACK_SCSV) {
    if (!CBB_add_u16(&child, SSL3_CK_FALLBACK_SCSV & 0xffff)) {
      return 0;
    }
  }

  return CBB_flush(out);
}

int ssl_write_client_hello(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  ScopedCBB cbb;
  CBB body;
  if (!ssl->method->init_message(ssl, cbb.get(), &body, SSL3_MT_CLIENT_HELLO)) {
    return 0;
  }

  // Renegotiations do not participate in session resumption.
  int has_session_id = ssl->session != NULL &&
                       !ssl->s3->initial_handshake_complete &&
                       ssl->session->session_id_length > 0;

  CBB child;
  if (!CBB_add_u16(&body, hs->client_version) ||
      !CBB_add_bytes(&body, ssl->s3->client_random, SSL3_RANDOM_SIZE) ||
      !CBB_add_u8_length_prefixed(&body, &child)) {
    return 0;
  }

  if (has_session_id) {
    if (!CBB_add_bytes(&child, ssl->session->session_id,
                       ssl->session->session_id_length)) {
      return 0;
    }
  } else {
    // In TLS 1.3 experimental encodings, send a fake placeholder session ID
    // when we do not otherwise have one to send.
    if (hs->max_version >= TLS1_3_VERSION &&
        ssl_is_resumption_variant(ssl->tls13_variant) &&
        !CBB_add_bytes(&child, hs->session_id, hs->session_id_len)) {
      return 0;
    }
  }

  if (SSL_is_dtls(ssl)) {
    if (!CBB_add_u8_length_prefixed(&body, &child) ||
        !CBB_add_bytes(&child, ssl->d1->cookie, ssl->d1->cookie_len)) {
      return 0;
    }
  }

  size_t header_len =
      SSL_is_dtls(ssl) ? DTLS1_HM_HEADER_LENGTH : SSL3_HM_HEADER_LENGTH;
  if (!ssl_write_client_cipher_list(hs, &body) ||
      !CBB_add_u8(&body, 1 /* one compression method */) ||
      !CBB_add_u8(&body, 0 /* null compression */) ||
      !ssl_add_clienthello_tlsext(hs, &body, header_len + CBB_len(&body))) {
    return 0;
  }

  uint8_t *msg = NULL;
  size_t len;
  if (!ssl->method->finish_message(ssl, cbb.get(), &msg, &len)) {
    return 0;
  }

  // Now that the length prefixes have been computed, fill in the placeholder
  // PSK binder.
  if (hs->needs_psk_binder &&
      !tls13_write_psk_binder(hs, msg, len)) {
    OPENSSL_free(msg);
    return 0;
  }

  return ssl->method->add_message(ssl, msg, len);
}

static int parse_server_version(SSL_HANDSHAKE *hs, uint16_t *out,
                                const SSLMessage &msg) {
  SSL *const ssl = hs->ssl;
  if (msg.type != SSL3_MT_SERVER_HELLO &&
      msg.type != SSL3_MT_HELLO_RETRY_REQUEST) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_UNEXPECTED_MESSAGE);
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNEXPECTED_MESSAGE);
    return 0;
  }

  CBS server_hello = msg.body;
  if (!CBS_get_u16(&server_hello, out)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return 0;
  }

  // The server version may also be in the supported_versions extension if
  // applicable.
  if (msg.type != SSL3_MT_SERVER_HELLO || *out != TLS1_2_VERSION) {
    return 1;
  }

  uint8_t sid_length;
  if (!CBS_skip(&server_hello, SSL3_RANDOM_SIZE) ||
      !CBS_get_u8(&server_hello, &sid_length) ||
      !CBS_skip(&server_hello, sid_length + 2 /* cipher_suite */ +
                1 /* compression_method */)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return 0;
  }

  // The extensions block may not be present.
  if (CBS_len(&server_hello) == 0) {
    return 1;
  }

  CBS extensions;
  if (!CBS_get_u16_length_prefixed(&server_hello, &extensions) ||
      CBS_len(&server_hello) != 0) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return 0;
  }

  bool have_supported_versions;
  CBS supported_versions;
  const SSL_EXTENSION_TYPE ext_types[] = {
    {TLSEXT_TYPE_supported_versions, &have_supported_versions,
     &supported_versions},
  };

  uint8_t alert = SSL_AD_DECODE_ERROR;
  if (!ssl_parse_extensions(&extensions, &alert, ext_types,
                            OPENSSL_ARRAY_SIZE(ext_types),
                            1 /* ignore unknown */)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, alert);
    return 0;
  }

  if (have_supported_versions &&
      (!CBS_get_u16(&supported_versions, out) ||
       CBS_len(&supported_versions) != 0)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return 0;
  }

  return 1;
}

static enum ssl_hs_wait_t do_start_connect(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  ssl_do_info_callback(ssl, SSL_CB_HANDSHAKE_START, 1);
  // |session_reused| must be reset in case this is a renegotiation.
  ssl->s3->session_reused = false;

  // Freeze the version range.
  if (!ssl_get_version_range(ssl, &hs->min_version, &hs->max_version)) {
    return ssl_hs_error;
  }

  // SSL 3.0 ClientHellos should use SSL 3.0 not TLS 1.0, for the record-layer
  // version.
  if (hs->max_version == SSL3_VERSION) {
    ssl->s3->aead_write_ctx->SetVersionIfNullCipher(SSL3_VERSION);
  }

  // Always advertise the ClientHello version from the original maximum version,
  // even on renegotiation. The static RSA key exchange uses this field, and
  // some servers fail when it changes across handshakes.
  if (SSL_is_dtls(hs->ssl)) {
    hs->client_version =
        hs->max_version >= TLS1_2_VERSION ? DTLS1_2_VERSION : DTLS1_VERSION;
  } else {
    hs->client_version =
        hs->max_version >= TLS1_2_VERSION ? TLS1_2_VERSION : hs->max_version;
  }

  // If the configured session has expired or was created at a disabled
  // version, drop it.
  if (ssl->session != NULL) {
    if (ssl->session->is_server ||
        !ssl_supports_version(hs, ssl->session->ssl_version) ||
        (ssl->session->session_id_length == 0 &&
         ssl->session->tlsext_ticklen == 0) ||
        ssl->session->not_resumable ||
        !ssl_session_is_time_valid(ssl, ssl->session)) {
      ssl_set_session(ssl, NULL);
    }
  }

  if (!RAND_bytes(ssl->s3->client_random, sizeof(ssl->s3->client_random))) {
    return ssl_hs_error;
  }

  // Initialize a random session ID for the experimental TLS 1.3 variant
  // requiring a session id.
  if (ssl_is_resumption_variant(ssl->tls13_variant)) {
    hs->session_id_len = sizeof(hs->session_id);
    if (!RAND_bytes(hs->session_id, hs->session_id_len)) {
      return ssl_hs_error;
    }
  }

  if (!ssl_write_client_hello(hs)) {
    return ssl_hs_error;
  }

  hs->state = state_enter_early_data;
  return ssl_hs_flush;
}

static enum ssl_hs_wait_t do_enter_early_data(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (SSL_is_dtls(ssl)) {
    hs->state = state_read_hello_verify_request;
    return ssl_hs_ok;
  }

  if (!hs->early_data_offered) {
    hs->state = state_read_server_hello;
    return ssl_hs_ok;
  }

  if (!tls13_init_early_key_schedule(hs) ||
      !tls13_advance_key_schedule(hs, ssl->session->master_key,
                                  ssl->session->master_key_length) ||
      !tls13_derive_early_secrets(hs) ||
      !tls13_set_traffic_key(ssl, evp_aead_seal, hs->early_traffic_secret,
                             hs->hash_len)) {
    return ssl_hs_error;
  }

  // Stash the early data session, so connection properties may be queried out
  // of it.
  hs->in_early_data = true;
  SSL_SESSION_up_ref(ssl->session);
  hs->early_session.reset(ssl->session);
  hs->can_early_write = true;

  hs->state = state_read_server_hello;
  return ssl_hs_early_return;
}

static enum ssl_hs_wait_t do_read_hello_verify_request(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  assert(SSL_is_dtls(ssl));

  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (msg.type != DTLS1_MT_HELLO_VERIFY_REQUEST) {
    hs->state = state_read_server_hello;
    return ssl_hs_ok;
  }

  CBS hello_verify_request = msg.body, cookie;
  uint16_t server_version;
  if (!CBS_get_u16(&hello_verify_request, &server_version) ||
      !CBS_get_u8_length_prefixed(&hello_verify_request, &cookie) ||
      CBS_len(&cookie) > sizeof(ssl->d1->cookie) ||
      CBS_len(&hello_verify_request) != 0) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return ssl_hs_error;
  }

  OPENSSL_memcpy(ssl->d1->cookie, CBS_data(&cookie), CBS_len(&cookie));
  ssl->d1->cookie_len = CBS_len(&cookie);

  ssl->method->next_message(ssl);

  // DTLS resets the handshake buffer after HelloVerifyRequest.
  if (!hs->transcript.Init()) {
    return ssl_hs_error;
  }

  if (!ssl_write_client_hello(hs)) {
    return ssl_hs_error;
  }

  hs->state = state_read_server_hello;
  return ssl_hs_flush;
}

static enum ssl_hs_wait_t do_read_server_hello(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_server_hello;
  }

  uint16_t server_version;
  if (!parse_server_version(hs, &server_version, msg)) {
    return ssl_hs_error;
  }

  if (!ssl_supports_version(hs, server_version)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNSUPPORTED_PROTOCOL);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_PROTOCOL_VERSION);
    return ssl_hs_error;
  }

  assert(ssl->s3->have_version == ssl->s3->initial_handshake_complete);
  if (!ssl->s3->have_version) {
    ssl->version = server_version;
    // At this point, the connection's version is known and ssl->version is
    // fixed. Begin enforcing the record-layer version.
    ssl->s3->have_version = true;
    ssl->s3->aead_write_ctx->SetVersionIfNullCipher(ssl->version);
  } else if (server_version != ssl->version) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_WRONG_SSL_VERSION);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_PROTOCOL_VERSION);
    return ssl_hs_error;
  }

  if (ssl3_protocol_version(ssl) >= TLS1_3_VERSION) {
    hs->state = state_tls13;
    return ssl_hs_ok;
  }

  if (hs->early_data_offered) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_WRONG_VERSION_ON_EARLY_DATA);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_PROTOCOL_VERSION);
    return ssl_hs_error;
  }

  ssl_clear_tls13_state(hs);

  if (!ssl_check_message_type(ssl, msg, SSL3_MT_SERVER_HELLO)) {
    return ssl_hs_error;
  }

  CBS server_hello = msg.body, server_random, session_id;
  uint16_t cipher_suite;
  uint8_t compression_method;
  if (!CBS_skip(&server_hello, 2 /* version */) ||
      !CBS_get_bytes(&server_hello, &server_random, SSL3_RANDOM_SIZE) ||
      !CBS_get_u8_length_prefixed(&server_hello, &session_id) ||
      CBS_len(&session_id) > SSL3_SESSION_ID_SIZE ||
      !CBS_get_u16(&server_hello, &cipher_suite) ||
      !CBS_get_u8(&server_hello, &compression_method)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return ssl_hs_error;
  }

  // Copy over the server random.
  OPENSSL_memcpy(ssl->s3->server_random, CBS_data(&server_random),
                 SSL3_RANDOM_SIZE);

  // TODO(davidben): Implement the TLS 1.1 and 1.2 downgrade sentinels once TLS
  // 1.3 is finalized and we are not implementing a draft version.

  if (!ssl->s3->initial_handshake_complete && ssl->session != NULL &&
      ssl->session->session_id_length != 0 &&
      CBS_mem_equal(&session_id, ssl->session->session_id,
                    ssl->session->session_id_length)) {
    ssl->s3->session_reused = true;
  } else {
    // The session wasn't resumed. Create a fresh SSL_SESSION to
    // fill out.
    ssl_set_session(ssl, NULL);
    if (!ssl_get_new_session(hs, 0 /* client */)) {
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
      return ssl_hs_error;
    }
    // Note: session_id could be empty.
    hs->new_session->session_id_length = CBS_len(&session_id);
    OPENSSL_memcpy(hs->new_session->session_id, CBS_data(&session_id),
                   CBS_len(&session_id));
  }

  const SSL_CIPHER *cipher = SSL_get_cipher_by_value(cipher_suite);
  if (cipher == NULL) {
    // unknown cipher
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNKNOWN_CIPHER_RETURNED);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
    return ssl_hs_error;
  }

  // The cipher must be allowed in the selected version and enabled.
  uint32_t mask_a, mask_k;
  ssl_get_client_disabled(ssl, &mask_a, &mask_k);
  if ((cipher->algorithm_mkey & mask_k) || (cipher->algorithm_auth & mask_a) ||
      SSL_CIPHER_get_min_version(cipher) > ssl3_protocol_version(ssl) ||
      SSL_CIPHER_get_max_version(cipher) < ssl3_protocol_version(ssl) ||
      !sk_SSL_CIPHER_find(SSL_get_ciphers(ssl), NULL, cipher)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_WRONG_CIPHER_RETURNED);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
    return ssl_hs_error;
  }

  if (ssl->session != NULL) {
    if (ssl->session->ssl_version != ssl->version) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_OLD_SESSION_VERSION_NOT_RETURNED);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
      return ssl_hs_error;
    }
    if (ssl->session->cipher != cipher) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_OLD_SESSION_CIPHER_NOT_RETURNED);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
      return ssl_hs_error;
    }
    if (!ssl_session_is_context_valid(ssl, ssl->session)) {
      // This is actually a client application bug.
      OPENSSL_PUT_ERROR(SSL,
                        SSL_R_ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
      return ssl_hs_error;
    }
  } else {
    hs->new_session->cipher = cipher;
  }
  hs->new_cipher = cipher;

  // Now that the cipher is known, initialize the handshake hash and hash the
  // ServerHello.
  if (!hs->transcript.InitHash(ssl3_protocol_version(ssl), hs->new_cipher) ||
      !ssl_hash_message(hs, msg)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
    return ssl_hs_error;
  }

  // If doing a full handshake, the server may request a client certificate
  // which requires hashing the handshake transcript. Otherwise, the handshake
  // buffer may be released.
  if (ssl->session != NULL ||
      !ssl_cipher_uses_certificate_auth(hs->new_cipher)) {
    hs->transcript.FreeBuffer();
  }

  // Only the NULL compression algorithm is supported.
  if (compression_method != 0) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
    return ssl_hs_error;
  }

  // TLS extensions
  if (!ssl_parse_serverhello_tlsext(hs, &server_hello)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_PARSE_TLSEXT);
    return ssl_hs_error;
  }

  // There should be nothing left over in the record.
  if (CBS_len(&server_hello) != 0) {
    // wrong packet length
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return ssl_hs_error;
  }

  if (ssl->session != NULL &&
      hs->extended_master_secret != ssl->session->extended_master_secret) {
    if (ssl->session->extended_master_secret) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_RESUMED_EMS_SESSION_WITHOUT_EMS_EXTENSION);
    } else {
      OPENSSL_PUT_ERROR(SSL, SSL_R_RESUMED_NON_EMS_SESSION_WITH_EMS_EXTENSION);
    }
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
    return ssl_hs_error;
  }

  ssl->method->next_message(ssl);

  if (ssl->session != NULL) {
    hs->state = state_read_session_ticket;
    return ssl_hs_ok;
  }

  hs->state = state_read_server_certificate;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_tls13(SSL_HANDSHAKE *hs) {
  enum ssl_hs_wait_t wait = tls13_client_handshake(hs);
  if (wait == ssl_hs_ok) {
    hs->state = state_finish_client_handshake;
    return ssl_hs_ok;
  }

  return wait;
}

static enum ssl_hs_wait_t do_read_server_certificate(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (!ssl_cipher_uses_certificate_auth(hs->new_cipher)) {
    hs->state = state_read_certificate_status;
    return ssl_hs_ok;
  }

  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (!ssl_check_message_type(ssl, msg, SSL3_MT_CERTIFICATE) ||
      !ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  CBS body = msg.body;
  uint8_t alert = SSL_AD_DECODE_ERROR;
  UniquePtr<STACK_OF(CRYPTO_BUFFER)> chain;
  if (!ssl_parse_cert_chain(&alert, &chain, &hs->peer_pubkey, NULL, &body,
                            ssl->ctx->pool)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, alert);
    return ssl_hs_error;
  }
  sk_CRYPTO_BUFFER_pop_free(hs->new_session->certs, CRYPTO_BUFFER_free);
  hs->new_session->certs = chain.release();

  if (sk_CRYPTO_BUFFER_num(hs->new_session->certs) == 0 ||
      CBS_len(&body) != 0 ||
      !ssl->ctx->x509_method->session_cache_objects(hs->new_session.get())) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return ssl_hs_error;
  }

  if (!ssl_check_leaf_certificate(
          hs, hs->peer_pubkey.get(),
          sk_CRYPTO_BUFFER_value(hs->new_session->certs, 0))) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
    return ssl_hs_error;
  }

  ssl->method->next_message(ssl);

  hs->state = state_read_certificate_status;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_certificate_status(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (!hs->certificate_status_expected) {
    hs->state = state_verify_server_certificate;
    return ssl_hs_ok;
  }

  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (msg.type != SSL3_MT_CERTIFICATE_STATUS) {
    // A server may send status_request in ServerHello and then change its mind
    // about sending CertificateStatus.
    hs->state = state_verify_server_certificate;
    return ssl_hs_ok;
  }

  if (!ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  CBS certificate_status = msg.body, ocsp_response;
  uint8_t status_type;
  if (!CBS_get_u8(&certificate_status, &status_type) ||
      status_type != TLSEXT_STATUSTYPE_ocsp ||
      !CBS_get_u24_length_prefixed(&certificate_status, &ocsp_response) ||
      CBS_len(&ocsp_response) == 0 ||
      CBS_len(&certificate_status) != 0) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    return ssl_hs_error;
  }

  CRYPTO_BUFFER_free(hs->new_session->ocsp_response);
  hs->new_session->ocsp_response =
      CRYPTO_BUFFER_new_from_CBS(&ocsp_response, ssl->ctx->pool);
  if (hs->new_session->ocsp_response == nullptr) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
    return ssl_hs_error;
  }

  ssl->method->next_message(ssl);

  hs->state = state_verify_server_certificate;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_verify_server_certificate(SSL_HANDSHAKE *hs) {
  if (!ssl_cipher_uses_certificate_auth(hs->new_cipher)) {
    hs->state = state_read_server_key_exchange;
    return ssl_hs_ok;
  }

  switch (ssl_verify_peer_cert(hs)) {
    case ssl_verify_ok:
      break;
    case ssl_verify_invalid:
      return ssl_hs_error;
    case ssl_verify_retry:
      hs->state = state_verify_server_certificate;
      return ssl_hs_certificate_verify;
  }

  hs->state = state_read_server_key_exchange;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_server_key_exchange(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (msg.type != SSL3_MT_SERVER_KEY_EXCHANGE) {
    // Some ciphers (pure PSK) have an optional ServerKeyExchange message.
    if (ssl_cipher_requires_server_key_exchange(hs->new_cipher)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_UNEXPECTED_MESSAGE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_UNEXPECTED_MESSAGE);
      return ssl_hs_error;
    }

    hs->state = state_read_certificate_request;
    return ssl_hs_ok;
  }

  if (!ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  uint32_t alg_k = hs->new_cipher->algorithm_mkey;
  uint32_t alg_a = hs->new_cipher->algorithm_auth;
  CBS server_key_exchange = msg.body;
  if (alg_a & SSL_aPSK) {
    CBS psk_identity_hint;

    // Each of the PSK key exchanges begins with a psk_identity_hint.
    if (!CBS_get_u16_length_prefixed(&server_key_exchange,
                                     &psk_identity_hint)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
      return ssl_hs_error;
    }

    // Store PSK identity hint for later use, hint is used in
    // ssl3_send_client_key_exchange.  Assume that the maximum length of a PSK
    // identity hint can be as long as the maximum length of a PSK identity.
    // Also do not allow NULL characters; identities are saved as C strings.
    //
    // TODO(davidben): Should invalid hints be ignored? It's a hint rather than
    // a specific identity.
    if (CBS_len(&psk_identity_hint) > PSK_MAX_IDENTITY_LEN ||
        CBS_contains_zero_byte(&psk_identity_hint)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DATA_LENGTH_TOO_LONG);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
      return ssl_hs_error;
    }

    // Save non-empty identity hints as a C string. Empty identity hints we
    // treat as missing. Plain PSK makes it possible to send either no hint
    // (omit ServerKeyExchange) or an empty hint, while ECDHE_PSK can only spell
    // empty hint. Having different capabilities is odd, so we interpret empty
    // and missing as identical.
    char *raw = nullptr;
    if (CBS_len(&psk_identity_hint) != 0 &&
        !CBS_strdup(&psk_identity_hint, &raw)) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_MALLOC_FAILURE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
      return ssl_hs_error;
    }
    hs->peer_psk_identity_hint.reset(raw);
  }

  if (alg_k & SSL_kECDHE) {
    // Parse the server parameters.
    uint8_t group_type;
    uint16_t group_id;
    CBS point;
    if (!CBS_get_u8(&server_key_exchange, &group_type) ||
        group_type != NAMED_CURVE_TYPE ||
        !CBS_get_u16(&server_key_exchange, &group_id) ||
        !CBS_get_u8_length_prefixed(&server_key_exchange, &point)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
      return ssl_hs_error;
    }
    hs->new_session->group_id = group_id;

    // Ensure the group is consistent with preferences.
    if (!tls1_check_group_id(ssl, group_id)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_WRONG_CURVE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_ILLEGAL_PARAMETER);
      return ssl_hs_error;
    }

    // Initialize ECDH and save the peer public key for later.
    hs->key_share = SSLKeyShare::Create(group_id);
    uint8_t *peer_key = nullptr;
    size_t peer_key_len = 0;
    if (!hs->key_share ||
        !CBS_stow(&point, &peer_key, &peer_key_len)) {
      return ssl_hs_error;
    }
    hs->peer_key.Reset(peer_key, peer_key_len);
  } else if (!(alg_k & SSL_kPSK)) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNEXPECTED_MESSAGE);
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_UNEXPECTED_MESSAGE);
    return ssl_hs_error;
  }

  // At this point, |server_key_exchange| contains the signature, if any, while
  // |msg.body| contains the entire message. From that, derive a CBS containing
  // just the parameter.
  CBS parameter;
  CBS_init(&parameter, CBS_data(&msg.body),
           CBS_len(&msg.body) - CBS_len(&server_key_exchange));

  // ServerKeyExchange should be signed by the server's public key.
  if (ssl_cipher_uses_certificate_auth(hs->new_cipher)) {
    uint16_t signature_algorithm = 0;
    if (ssl3_protocol_version(ssl) >= TLS1_2_VERSION) {
      if (!CBS_get_u16(&server_key_exchange, &signature_algorithm)) {
        OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
        ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
        return ssl_hs_error;
      }
      uint8_t alert = SSL_AD_DECODE_ERROR;
      if (!tls12_check_peer_sigalg(ssl, &alert, signature_algorithm)) {
        ssl3_send_alert(ssl, SSL3_AL_FATAL, alert);
        return ssl_hs_error;
      }
      hs->new_session->peer_signature_algorithm = signature_algorithm;
    } else if (!tls1_get_legacy_signature_algorithm(&signature_algorithm,
                                                    hs->peer_pubkey.get())) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_UNSUPPORTED_CERTIFICATE);
      return ssl_hs_error;
    }

    // The last field in |server_key_exchange| is the signature.
    CBS signature;
    if (!CBS_get_u16_length_prefixed(&server_key_exchange, &signature) ||
        CBS_len(&server_key_exchange) != 0) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
      return ssl_hs_error;
    }

    ScopedCBB transcript;
    uint8_t *transcript_data;
    size_t transcript_len;
    if (!CBB_init(transcript.get(),
                  2 * SSL3_RANDOM_SIZE + CBS_len(&parameter)) ||
        !CBB_add_bytes(transcript.get(), ssl->s3->client_random,
                       SSL3_RANDOM_SIZE) ||
        !CBB_add_bytes(transcript.get(), ssl->s3->server_random,
                       SSL3_RANDOM_SIZE) ||
        !CBB_add_bytes(transcript.get(), CBS_data(&parameter),
                       CBS_len(&parameter)) ||
        !CBB_finish(transcript.get(), &transcript_data, &transcript_len)) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
      return ssl_hs_error;
    }

    int sig_ok = ssl_public_key_verify(
        ssl, CBS_data(&signature), CBS_len(&signature), signature_algorithm,
        hs->peer_pubkey.get(), transcript_data, transcript_len);
    OPENSSL_free(transcript_data);

#if defined(BORINGSSL_UNSAFE_FUZZER_MODE)
    sig_ok = 1;
    ERR_clear_error();
#endif
    if (!sig_ok) {
      // bad signature
      OPENSSL_PUT_ERROR(SSL, SSL_R_BAD_SIGNATURE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECRYPT_ERROR);
      return ssl_hs_error;
    }
  } else {
    // PSK ciphers are the only supported certificate-less ciphers.
    assert(alg_a == SSL_aPSK);

    if (CBS_len(&server_key_exchange) > 0) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_EXTRA_DATA_IN_MESSAGE);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
      return ssl_hs_error;
    }
  }

  ssl->method->next_message(ssl);
  hs->state = state_read_certificate_request;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_certificate_request(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (!ssl_cipher_uses_certificate_auth(hs->new_cipher)) {
    hs->state = state_read_server_hello_done;
    return ssl_hs_ok;
  }

  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (msg.type == SSL3_MT_SERVER_HELLO_DONE) {
    // If we get here we don't need the handshake buffer as we won't be doing
    // client auth.
    hs->transcript.FreeBuffer();
    hs->state = state_read_server_hello_done;
    return ssl_hs_ok;
  }

  if (!ssl_check_message_type(ssl, msg, SSL3_MT_CERTIFICATE_REQUEST) ||
      !ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  // Get the certificate types.
  CBS body = msg.body, certificate_types;
  if (!CBS_get_u8_length_prefixed(&body, &certificate_types)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    return ssl_hs_error;
  }

  if (!CBS_stow(&certificate_types, &hs->certificate_types,
                &hs->num_certificate_types)) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
    return ssl_hs_error;
  }

  if (ssl3_protocol_version(ssl) >= TLS1_2_VERSION) {
    CBS supported_signature_algorithms;
    if (!CBS_get_u16_length_prefixed(&body, &supported_signature_algorithms) ||
        !tls1_parse_peer_sigalgs(hs, &supported_signature_algorithms)) {
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      return ssl_hs_error;
    }
  }

  uint8_t alert = SSL_AD_DECODE_ERROR;
  UniquePtr<STACK_OF(CRYPTO_BUFFER)> ca_names =
      ssl_parse_client_CA_list(ssl, &alert, &body);
  if (!ca_names) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, alert);
    return ssl_hs_error;
  }

  if (CBS_len(&body) != 0) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    return ssl_hs_error;
  }

  hs->cert_request = true;
  hs->ca_names = std::move(ca_names);
  ssl->ctx->x509_method->hs_flush_cached_ca_names(hs);

  ssl->method->next_message(ssl);
  hs->state = state_read_server_hello_done;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_server_hello_done(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (!ssl_check_message_type(ssl, msg, SSL3_MT_SERVER_HELLO_DONE) ||
      !ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  // ServerHelloDone is empty.
  if (CBS_len(&msg.body) != 0) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    return ssl_hs_error;
  }

  ssl->method->next_message(ssl);
  hs->state = state_send_client_certificate;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_send_client_certificate(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  // The peer didn't request a certificate.
  if (!hs->cert_request) {
    hs->state = state_send_client_key_exchange;
    return ssl_hs_ok;
  }

  // Call cert_cb to update the certificate.
  if (ssl->cert->cert_cb != NULL) {
    int rv = ssl->cert->cert_cb(ssl, ssl->cert->cert_cb_arg);
    if (rv == 0) {
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_INTERNAL_ERROR);
      OPENSSL_PUT_ERROR(SSL, SSL_R_CERT_CB_ERROR);
      return ssl_hs_error;
    }
    if (rv < 0) {
      hs->state = state_send_client_certificate;
      return ssl_hs_x509_lookup;
    }
  }

  if (!ssl_has_certificate(ssl)) {
    // Without a client certificate, the handshake buffer may be released.
    hs->transcript.FreeBuffer();

    // In SSL 3.0, the Certificate message is replaced with a warning alert.
    if (ssl->version == SSL3_VERSION) {
      if (!ssl->method->add_alert(ssl, SSL3_AL_WARNING,
                                  SSL_AD_NO_CERTIFICATE)) {
        return ssl_hs_error;
      }
      hs->state = state_send_client_key_exchange;
      return ssl_hs_ok;
    }
  }

  if (!ssl_on_certificate_selected(hs) ||
      !ssl3_output_cert_chain(ssl)) {
    return ssl_hs_error;
  }


  hs->state = state_send_client_key_exchange;
  return ssl_hs_ok;
}

static_assert(sizeof(size_t) >= sizeof(unsigned),
              "size_t is smaller than unsigned");

static enum ssl_hs_wait_t do_send_client_key_exchange(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  ScopedCBB cbb;
  CBB body;
  if (!ssl->method->init_message(ssl, cbb.get(), &body,
                                 SSL3_MT_CLIENT_KEY_EXCHANGE)) {
    return ssl_hs_error;
  }

  Array<uint8_t> pms;
  uint32_t alg_k = hs->new_cipher->algorithm_mkey;
  uint32_t alg_a = hs->new_cipher->algorithm_auth;

  // If using a PSK key exchange, prepare the pre-shared key.
  unsigned psk_len = 0;
  uint8_t psk[PSK_MAX_PSK_LEN];
  if (alg_a & SSL_aPSK) {
    if (ssl->psk_client_callback == NULL) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_PSK_NO_CLIENT_CB);
      return ssl_hs_error;
    }

    char identity[PSK_MAX_IDENTITY_LEN + 1];
    OPENSSL_memset(identity, 0, sizeof(identity));
    psk_len =
        ssl->psk_client_callback(ssl, hs->peer_psk_identity_hint.get(),
                                 identity, sizeof(identity), psk, sizeof(psk));
    if (psk_len == 0) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_PSK_IDENTITY_NOT_FOUND);
      ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
      return ssl_hs_error;
    }
    assert(psk_len <= PSK_MAX_PSK_LEN);

    OPENSSL_free(hs->new_session->psk_identity);
    hs->new_session->psk_identity = BUF_strdup(identity);
    if (hs->new_session->psk_identity == NULL) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_MALLOC_FAILURE);
      return ssl_hs_error;
    }

    // Write out psk_identity.
    CBB child;
    if (!CBB_add_u16_length_prefixed(&body, &child) ||
        !CBB_add_bytes(&child, (const uint8_t *)identity,
                       OPENSSL_strnlen(identity, sizeof(identity))) ||
        !CBB_flush(&body)) {
      return ssl_hs_error;
    }
  }

  // Depending on the key exchange method, compute |pms|.
  if (alg_k & SSL_kRSA) {
    if (!pms.Init(SSL_MAX_MASTER_KEY_LENGTH)) {
      return ssl_hs_error;
    }

    RSA *rsa = EVP_PKEY_get0_RSA(hs->peer_pubkey.get());
    if (rsa == NULL) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      return ssl_hs_error;
    }

    pms[0] = hs->client_version >> 8;
    pms[1] = hs->client_version & 0xff;
    if (!RAND_bytes(&pms[2], SSL_MAX_MASTER_KEY_LENGTH - 2)) {
      return ssl_hs_error;
    }

    CBB child, *enc_pms = &body;
    size_t enc_pms_len;
    // In TLS, there is a length prefix.
    if (ssl->version > SSL3_VERSION) {
      if (!CBB_add_u16_length_prefixed(&body, &child)) {
        return ssl_hs_error;
      }
      enc_pms = &child;
    }

    uint8_t *ptr;
    if (!CBB_reserve(enc_pms, &ptr, RSA_size(rsa)) ||
        !RSA_encrypt(rsa, &enc_pms_len, ptr, RSA_size(rsa), pms.data(),
                     pms.size(), RSA_PKCS1_PADDING) ||
        !CBB_did_write(enc_pms, enc_pms_len) ||
        !CBB_flush(&body)) {
      return ssl_hs_error;
    }
  } else if (alg_k & SSL_kECDHE) {
    // Generate a keypair and serialize the public half.
    CBB child;
    if (!CBB_add_u8_length_prefixed(&body, &child)) {
      return ssl_hs_error;
    }

    // Compute the premaster.
    uint8_t alert = SSL_AD_DECODE_ERROR;
    if (!hs->key_share->Accept(&child, &pms, &alert, hs->peer_key)) {
      ssl3_send_alert(ssl, SSL3_AL_FATAL, alert);
      return ssl_hs_error;
    }
    if (!CBB_flush(&body)) {
      return ssl_hs_error;
    }

    // The key exchange state may now be discarded.
    hs->key_share.reset();
    hs->peer_key.Reset();
  } else if (alg_k & SSL_kPSK) {
    // For plain PSK, other_secret is a block of 0s with the same length as
    // the pre-shared key.
    if (!pms.Init(psk_len)) {
      return ssl_hs_error;
    }
    OPENSSL_memset(pms.data(), 0, pms.size());
  } else {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_HANDSHAKE_FAILURE);
    OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
    return ssl_hs_error;
  }

  // For a PSK cipher suite, other_secret is combined with the pre-shared
  // key.
  if (alg_a & SSL_aPSK) {
    ScopedCBB pms_cbb;
    CBB child;
    uint8_t *new_pms;
    size_t new_pms_len;

    if (!CBB_init(pms_cbb.get(), 2 + psk_len + 2 + pms.size()) ||
        !CBB_add_u16_length_prefixed(pms_cbb.get(), &child) ||
        !CBB_add_bytes(&child, pms.data(), pms.size()) ||
        !CBB_add_u16_length_prefixed(pms_cbb.get(), &child) ||
        !CBB_add_bytes(&child, psk, psk_len) ||
        !CBB_finish(pms_cbb.get(), &new_pms, &new_pms_len)) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_MALLOC_FAILURE);
      return ssl_hs_error;
    }
    pms.Reset(new_pms, new_pms_len);
  }

  // The message must be added to the finished hash before calculating the
  // master secret.
  if (!ssl_add_message_cbb(ssl, cbb.get())) {
    return ssl_hs_error;
  }

  hs->new_session->master_key_length = tls1_generate_master_secret(
      hs, hs->new_session->master_key, pms.data(), pms.size());
  if (hs->new_session->master_key_length == 0) {
    return ssl_hs_error;
  }
  hs->new_session->extended_master_secret = hs->extended_master_secret;

  hs->state = state_send_client_certificate_verify;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_send_client_certificate_verify(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (!hs->cert_request || !ssl_has_certificate(ssl)) {
    hs->state = state_send_client_finished;
    return ssl_hs_ok;
  }

  assert(ssl_has_private_key(ssl));
  ScopedCBB cbb;
  CBB body, child;
  if (!ssl->method->init_message(ssl, cbb.get(), &body,
                                 SSL3_MT_CERTIFICATE_VERIFY)) {
    return ssl_hs_error;
  }

  uint16_t signature_algorithm;
  if (!tls1_choose_signature_algorithm(hs, &signature_algorithm)) {
    return ssl_hs_error;
  }
  if (ssl3_protocol_version(ssl) >= TLS1_2_VERSION) {
    // Write out the digest type in TLS 1.2.
    if (!CBB_add_u16(&body, signature_algorithm)) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      return ssl_hs_error;
    }
  }

  // Set aside space for the signature.
  const size_t max_sig_len = EVP_PKEY_size(hs->local_pubkey.get());
  uint8_t *ptr;
  if (!CBB_add_u16_length_prefixed(&body, &child) ||
      !CBB_reserve(&child, &ptr, max_sig_len)) {
    return ssl_hs_error;
  }

  size_t sig_len = max_sig_len;
  // The SSL3 construction for CertificateVerify does not decompose into a
  // single final digest and signature, and must be special-cased.
  if (ssl3_protocol_version(ssl) == SSL3_VERSION) {
    if (ssl->cert->key_method != NULL) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_UNSUPPORTED_PROTOCOL_FOR_CUSTOM_KEY);
      return ssl_hs_error;
    }

    uint8_t digest[EVP_MAX_MD_SIZE];
    size_t digest_len;
    if (!hs->transcript.GetSSL3CertVerifyHash(
            digest, &digest_len, hs->new_session.get(), signature_algorithm)) {
      return ssl_hs_error;
    }

    UniquePtr<EVP_PKEY_CTX> pctx(EVP_PKEY_CTX_new(ssl->cert->privatekey, NULL));
    if (!pctx ||
        !EVP_PKEY_sign_init(pctx.get()) ||
        !EVP_PKEY_sign(pctx.get(), ptr, &sig_len, digest, digest_len)) {
      return ssl_hs_error;
    }
  } else {
    switch (ssl_private_key_sign(
        hs, ptr, &sig_len, max_sig_len, signature_algorithm,
        hs->transcript.buffer_data(), hs->transcript.buffer_len())) {
      case ssl_private_key_success:
        break;
      case ssl_private_key_failure:
        return ssl_hs_error;
      case ssl_private_key_retry:
        hs->state = state_send_client_certificate_verify;
        return ssl_hs_private_key_operation;
    }
  }

  if (!CBB_did_write(&child, sig_len) ||
      !ssl_add_message_cbb(ssl, cbb.get())) {
    return ssl_hs_error;
  }

  // The handshake buffer is no longer necessary.
  hs->transcript.FreeBuffer();

  hs->state = state_send_client_finished;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_send_client_finished(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  // Resolve Channel ID first, before any non-idempotent operations.
  if (ssl->s3->tlsext_channel_id_valid) {
    if (!ssl_do_channel_id_callback(ssl)) {
      return ssl_hs_error;
    }

    if (ssl->tlsext_channel_id_private == NULL) {
      hs->state = state_send_client_finished;
      return ssl_hs_channel_id_lookup;
    }
  }

  if (!ssl->method->add_change_cipher_spec(ssl) ||
      !tls1_change_cipher_state(hs, evp_aead_seal)) {
    return ssl_hs_error;
  }

  if (hs->next_proto_neg_seen) {
    static const uint8_t kZero[32] = {0};
    size_t padding_len = 32 - ((ssl->s3->next_proto_negotiated_len + 2) % 32);

    ScopedCBB cbb;
    CBB body, child;
    if (!ssl->method->init_message(ssl, cbb.get(), &body, SSL3_MT_NEXT_PROTO) ||
        !CBB_add_u8_length_prefixed(&body, &child) ||
        !CBB_add_bytes(&child, ssl->s3->next_proto_negotiated,
                       ssl->s3->next_proto_negotiated_len) ||
        !CBB_add_u8_length_prefixed(&body, &child) ||
        !CBB_add_bytes(&child, kZero, padding_len) ||
        !ssl_add_message_cbb(ssl, cbb.get())) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      return ssl_hs_error;
    }
  }

  if (ssl->s3->tlsext_channel_id_valid) {
    ScopedCBB cbb;
    CBB body;
    if (!ssl->method->init_message(ssl, cbb.get(), &body, SSL3_MT_CHANNEL_ID) ||
        !tls1_write_channel_id(hs, &body) ||
        !ssl_add_message_cbb(ssl, cbb.get())) {
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      return ssl_hs_error;
    }
  }

  if (!ssl3_send_finished(hs)) {
    return ssl_hs_error;
  }

  hs->state = state_finish_flight;
  return ssl_hs_flush;
}

static enum ssl_hs_wait_t do_finish_flight(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  if (ssl->session != NULL) {
    hs->state = state_finish_client_handshake;
    return ssl_hs_ok;
  }

  // This is a full handshake. If it involves ChannelID, then record the
  // handshake hashes at this point in the session so that any resumption of
  // this session with ChannelID can sign those hashes.
  if (!tls1_record_handshake_hashes_for_channel_id(hs)) {
    return ssl_hs_error;
  }

  hs->state = state_read_session_ticket;

  if ((SSL_get_mode(ssl) & SSL_MODE_ENABLE_FALSE_START) &&
      ssl3_can_false_start(ssl) &&
      // No False Start on renegotiation (would complicate the state machine).
      !ssl->s3->initial_handshake_complete) {
    hs->in_false_start = true;
    hs->can_early_write = true;
    return ssl_hs_early_return;
  }

  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_session_ticket(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  if (!hs->ticket_expected) {
    hs->state = state_process_change_cipher_spec;
    return ssl_hs_read_change_cipher_spec;
  }

  SSLMessage msg;
  if (!ssl->method->get_message(ssl, &msg)) {
    return ssl_hs_read_message;
  }

  if (!ssl_check_message_type(ssl, msg, SSL3_MT_NEW_SESSION_TICKET) ||
      !ssl_hash_message(hs, msg)) {
    return ssl_hs_error;
  }

  CBS new_session_ticket = msg.body, ticket;
  uint32_t tlsext_tick_lifetime_hint;
  if (!CBS_get_u32(&new_session_ticket, &tlsext_tick_lifetime_hint) ||
      !CBS_get_u16_length_prefixed(&new_session_ticket, &ticket) ||
      CBS_len(&new_session_ticket) != 0) {
    ssl3_send_alert(ssl, SSL3_AL_FATAL, SSL_AD_DECODE_ERROR);
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    return ssl_hs_error;
  }

  if (CBS_len(&ticket) == 0) {
    // RFC 5077 allows a server to change its mind and send no ticket after
    // negotiating the extension. The value of |ticket_expected| is checked in
    // |ssl_update_cache| so is cleared here to avoid an unnecessary update.
    hs->ticket_expected = false;
    ssl->method->next_message(ssl);
    hs->state = state_process_change_cipher_spec;
    return ssl_hs_read_change_cipher_spec;
  }

  SSL_SESSION *session = hs->new_session.get();
  UniquePtr<SSL_SESSION> renewed_session;
  if (ssl->session != NULL) {
    // The server is sending a new ticket for an existing session. Sessions are
    // immutable once established, so duplicate all but the ticket of the
    // existing session.
    renewed_session =
        SSL_SESSION_dup(ssl->session, SSL_SESSION_INCLUDE_NONAUTH);
    if (!renewed_session) {
      // This should never happen.
      OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
      return ssl_hs_error;
    }
    session = renewed_session.get();
  }

  // |tlsext_tick_lifetime_hint| is measured from when the ticket was issued.
  ssl_session_rebase_time(ssl, session);

  if (!CBS_stow(&ticket, &session->tlsext_tick, &session->tlsext_ticklen)) {
    OPENSSL_PUT_ERROR(SSL, ERR_R_MALLOC_FAILURE);
    return ssl_hs_error;
  }
  session->tlsext_tick_lifetime_hint = tlsext_tick_lifetime_hint;

  // Generate a session ID for this session based on the session ticket. We use
  // the session ID mechanism for detecting ticket resumption. This also fits in
  // with assumptions elsewhere in OpenSSL.
  if (!EVP_Digest(CBS_data(&ticket), CBS_len(&ticket),
                  session->session_id, &session->session_id_length,
                  EVP_sha256(), NULL)) {
    return ssl_hs_error;
  }

  if (renewed_session) {
    session->not_resumable = 0;
    SSL_SESSION_free(ssl->session);
    ssl->session = renewed_session.release();
  }

  ssl->method->next_message(ssl);
  hs->state = state_process_change_cipher_spec;
  return ssl_hs_read_change_cipher_spec;
}

static enum ssl_hs_wait_t do_process_change_cipher_spec(SSL_HANDSHAKE *hs) {
  if (!tls1_change_cipher_state(hs, evp_aead_open)) {
    return ssl_hs_error;
  }

  hs->state = state_read_server_finished;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_read_server_finished(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;
  enum ssl_hs_wait_t wait = ssl_get_finished(hs);
  if (wait != ssl_hs_ok) {
    return wait;
  }

  if (ssl->session != NULL) {
    hs->state = state_send_client_finished;
    return ssl_hs_ok;
  }

  hs->state = state_finish_client_handshake;
  return ssl_hs_ok;
}

static enum ssl_hs_wait_t do_finish_client_handshake(SSL_HANDSHAKE *hs) {
  SSL *const ssl = hs->ssl;

  ssl->method->on_handshake_complete(ssl);

  SSL_SESSION_free(ssl->s3->established_session);
  if (ssl->session != NULL) {
    SSL_SESSION_up_ref(ssl->session);
    ssl->s3->established_session = ssl->session;
  } else {
    // We make a copy of the session in order to maintain the immutability
    // of the new established_session due to False Start. The caller may
    // have taken a reference to the temporary session.
    ssl->s3->established_session =
        SSL_SESSION_dup(hs->new_session.get(), SSL_SESSION_DUP_ALL)
        .release();
    if (ssl->s3->established_session == NULL) {
      return ssl_hs_error;
    }
    // Renegotiations do not participate in session resumption.
    if (!ssl->s3->initial_handshake_complete) {
      ssl->s3->established_session->not_resumable = 0;
    }

    hs->new_session.reset();
  }

  hs->handshake_finalized = true;
  ssl->s3->initial_handshake_complete = true;
  ssl_update_cache(hs, SSL_SESS_CACHE_CLIENT);

  hs->state = state_done;
  return ssl_hs_ok;
}

enum ssl_hs_wait_t ssl_client_handshake(SSL_HANDSHAKE *hs) {
  while (hs->state != state_done) {
    enum ssl_hs_wait_t ret = ssl_hs_error;
    enum ssl_client_hs_state_t state =
        static_cast<enum ssl_client_hs_state_t>(hs->state);
    switch (state) {
      case state_start_connect:
        ret = do_start_connect(hs);
        break;
      case state_enter_early_data:
        ret = do_enter_early_data(hs);
        break;
      case state_read_hello_verify_request:
        ret = do_read_hello_verify_request(hs);
        break;
      case state_read_server_hello:
        ret = do_read_server_hello(hs);
        break;
      case state_tls13:
        ret = do_tls13(hs);
        break;
      case state_read_server_certificate:
        ret = do_read_server_certificate(hs);
        break;
      case state_read_certificate_status:
        ret = do_read_certificate_status(hs);
        break;
      case state_verify_server_certificate:
        ret = do_verify_server_certificate(hs);
        break;
      case state_read_server_key_exchange:
        ret = do_read_server_key_exchange(hs);
        break;
      case state_read_certificate_request:
        ret = do_read_certificate_request(hs);
        break;
      case state_read_server_hello_done:
        ret = do_read_server_hello_done(hs);
        break;
      case state_send_client_certificate:
        ret = do_send_client_certificate(hs);
        break;
      case state_send_client_key_exchange:
        ret = do_send_client_key_exchange(hs);
        break;
      case state_send_client_certificate_verify:
        ret = do_send_client_certificate_verify(hs);
        break;
      case state_send_client_finished:
        ret = do_send_client_finished(hs);
        break;
      case state_finish_flight:
        ret = do_finish_flight(hs);
        break;
      case state_read_session_ticket:
        ret = do_read_session_ticket(hs);
        break;
      case state_process_change_cipher_spec:
        ret = do_process_change_cipher_spec(hs);
        break;
      case state_read_server_finished:
        ret = do_read_server_finished(hs);
        break;
      case state_finish_client_handshake:
        ret = do_finish_client_handshake(hs);
        break;
      case state_done:
        ret = ssl_hs_ok;
        break;
    }

    if (hs->state != state) {
      ssl_do_info_callback(hs->ssl, SSL_CB_CONNECT_LOOP, 1);
    }

    if (ret != ssl_hs_ok) {
      return ret;
    }
  }

  ssl_do_info_callback(hs->ssl, SSL_CB_HANDSHAKE_DONE, 1);
  return ssl_hs_ok;
}

const char *ssl_client_handshake_state(SSL_HANDSHAKE *hs) {
  enum ssl_client_hs_state_t state =
      static_cast<enum ssl_client_hs_state_t>(hs->state);
  switch (state) {
    case state_start_connect:
      return "TLS client start_connect";
    case state_enter_early_data:
      return "TLS client enter_early_data";
    case state_read_hello_verify_request:
      return "TLS client read_hello_verify_request";
    case state_read_server_hello:
      return "TLS client read_server_hello";
    case state_tls13:
      return tls13_client_handshake_state(hs);
    case state_read_server_certificate:
      return "TLS client read_server_certificate";
    case state_read_certificate_status:
      return "TLS client read_certificate_status";
    case state_verify_server_certificate:
      return "TLS client verify_server_certificate";
    case state_read_server_key_exchange:
      return "TLS client read_server_key_exchange";
    case state_read_certificate_request:
      return "TLS client read_certificate_request";
    case state_read_server_hello_done:
      return "TLS client read_server_hello_done";
    case state_send_client_certificate:
      return "TLS client send_client_certificate";
    case state_send_client_key_exchange:
      return "TLS client send_client_key_exchange";
    case state_send_client_certificate_verify:
      return "TLS client send_client_certificate_verify";
    case state_send_client_finished:
      return "TLS client send_client_finished";
    case state_finish_flight:
      return "TLS client finish_flight";
    case state_read_session_ticket:
      return "TLS client read_session_ticket";
    case state_process_change_cipher_spec:
      return "TLS client process_change_cipher_spec";
    case state_read_server_finished:
      return "TLS client read_server_finished";
    case state_finish_client_handshake:
      return "TLS client finish_client_handshake";
    case state_done:
      return "TLS client done";
  }

  return "TLS client unknown";
}

}
