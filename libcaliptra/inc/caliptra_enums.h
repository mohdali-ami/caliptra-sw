// Licensed under the Apache-2.0 license
#pragma once

#include <stdint.h>

/**
 * libcaliptra_error
 *
 * Error codes for all possible lib caliptra failures
 */
enum libcaliptra_error {
    NO_ERROR = 0,
    // General API
    INVALID_PARAMS              = 0x100,
    API_INTERNAL_ERROR          = 0x101,
    REG_ACCESS_ERROR            = 0x102,
    PAUSER_LOCKED               = 0x103,
    FW_LOAD_NOT_IN_PROGRESS     = 0x104,
    // Fuse
    NOT_READY_FOR_FUSES         = 0x200,
    STILL_READY_FOR_FUSES       = 0x201,
    // Mailbox
    MBX_BUSY                    = 0x300,
    MBX_NO_MSG_PENDING          = 0x301,
    MBX_COMPLETE_NOT_READY      = 0x302,
    MBX_STATUS_FAILED           = 0x303,
    MBX_STATUS_UNKNOWN          = 0x304,
    MBX_STATUS_NOT_IDLE         = 0x305,
    MBX_RESP_NO_HEADER          = 0x306,
    MBX_RESP_CHKSUM_INVALID     = 0x307,
    MBX_RESP_FIPS_NOT_APPROVED  = 0x308,

    // MFG
    IDEV_CSR_NOT_READY = 0x400,
};

/**
 * fw_load_piecewise_state
 *
 * Tracks state for piecewise FW loading to enforce correct flow
 */
enum fw_load_piecewise_state {
    FW_LOAD_PIECEWISE_IDLE = 0,
    FW_LOAD_PIECEWISE_IN_PROGRESS = 1,
};

/**
 * device_lifecycle
 *
 * Device life cycle states
 */
enum device_lifecycle {
    Unprovisioned = 0,
    Manufacturing = 1,
    Reserved2 = 2,
    Production = 3,
};

/**
 * fips_status
 *
 * All valid FIPS status codes.
 */
enum fips_status {
    FIPS_STATUS_APPROVED = 0,
};

/**
 * toc_entry_id
 *
 * Table of contents entry IDs used in the FW manifest
 */
enum toc_entry_id {
    FMC     = 0x00000001,
    Runtime = 0x00000002,
    MAX     = 0xFFFFFFFF,
};

// Enums used in Caliptra mailbox command requests and responses
/**
 * certify_key_extended_flags
 *
 * CERTIFY_KEY_EXTENDED flags options.
 */
enum certify_key_extended_flags {
    DMTF_OTHER_NAME = ( 1UL << 31),
};

/**
 * set_auth_manifest_manifest_flags
 *
 * SET_AUTH_MANIFEST manifest_flags options.
 */
enum set_auth_manifest_manifest_flags {
    VENDOR_SIGNATURE_REQUIRED = ( 1UL << 0),
};

/**
 * authorize_and_stash_flags
 *
 * AUTHORIZE_AND_STASH flags options.
 */
enum authorize_and_stash_flags {
    SKIP_STASH = ( 1UL << 0),
};

/**
 * authorize_and_stash_source
 *
 * AUTHORIZE_AND_STASH source values.
 */
enum authorize_and_stash_source {
    IN_REQUEST = 0x1,
};

/**
 * authorize_and_stash_auth_req_result
 *
 * AUTHORIZE_AND_STASH auth_req_result values.
 */
enum authorize_and_stash_auth_req_result {
    AUTHORIZE_IMAGE      = 0xDEADC0DE,
    IMAGE_NOT_AUTHORIZED = 0x21523F21,
    IMAGE_HASH_MISMATCH  = 0x8BFB95CB,
};

// The below enums are placeholders to set up the baseline
// required for communication of DPE commands to Caliptra
// firmware.

enum dpe_commands {
    DPE_GET_PROFILE        = 0x1,
    DPE_INITIALIZE_CONTEXT = 0x7,
    DPE_DERIVE_CONTEXT     = 0x8,
    DPE_CERTIFY_KEY        = 0x9,
    DPE_SIGN               = 0xA,
    DPE_ROTATE_CTX_HANDLE  = 0xE,
    DPE_DESTROY_CTX        = 0xF,
    DPE_GET_CERT_CHAIN     = 0x10,
};

enum dpe_error_codes {
    DPE_NO_ERROR               = 0,
    DPE_INTERNAL_ERROR         = 1,
    DPE_INVALID_COMMAND        = 2,
    DPE_INVALID_ARGUMENT       = 3,
    DPE_ARGUMENT_NOT_SUPPORTED = 4,
    DPE_INVALID_HANDLE         = 0x1000,
    DPE_INVALID_LOCALITY       = 0x1001,
    DPE_BADTAG                 = 0x1002,
    DPE_MAXTCIS                = 0x1003,
    DPE_PLATFORM_ERROR         = 0x1004,
    DPE_CRYPTO_ERROR           = 0x1005,
    DPE_HASH_ERROR             = 0x1006,
    DPE_RAND_ERROR             = 0x1007,
};

enum dpe_derive_context_cmd_flags {
    DPE_DERIVE_CONTEXT_FLAG_RETAIN_PARENT_CONTEXT = ( 1UL << 29),
    DPE_DERIVE_CONTEXT_FLAG_RECURSIVE             = ( 1UL << 24),
    DPE_DERIVE_CONTEXT_FLAG_EXPORT_CDI            = ( 1UL << 23),
    DPE_DERIVE_CONTEXT_FLAG_CREATE_CERTIFICATE    = ( 1UL << 22),
};

#define DPE_PROFILE_256 3
#define DPE_PROFILE_384 4

enum dpe_profile {
    P256Sha256 = DPE_PROFILE_256,
    P384Sha384 = DPE_PROFILE_384,
};
