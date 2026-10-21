#ifndef PORT_MSM_SWAP_H
#define PORT_MSM_SWAP_H

// Byte-swapping for the sound manager's disc data (mpgcsnd.msm, mpgcstr.pdt),
// which is big-endian: each structure is swapped once, right after it is
// read (src/msm, under TARGET_PC). Implemented by the port.

#include "dolphin/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void port_msm_swap_header(void *header);                 // MSM_HEADER
void port_msm_swap_info(void *info);                     // MSM_INFO
void port_msm_swap_auxparams(void *aux, u32 size);       // MSM_AUXPARAM[]
void port_msm_swap_grpinfo(void *info, u32 size);        // MSM_GRP_INFO[]
void port_msm_swap_group(void *grp, u32 size);           // MSM_GRP_HEAD + MusyX proj/pool/sdir
void port_msm_swap_mus(void *mus, u32 size);             // MSM_MUS[]
void port_msm_swap_se(void *se, u32 size);               // MSM_SE[]
// A song is swapped the first time it plays (it may sit inside a group, which
// is swapped and reloaded as a whole).
void port_msm_song_ready(void *song, u32 size);
// A buffer that held songs was read again.
void port_msm_forget_songs(void *base, u32 size);
void port_msm_swap_stream_header(void *header);          // MSM_STREAM_HEADER
// The stream pack list (u32 offsets), the packs it points at (relative to
// packOfs in the file) and the ADPCM coefficient tables.
void port_msm_swap_streams(u32 *list, u32 listCount, void *packs, u32 packsSize, u32 packOfs, void *adpcm, u32 adpcmSize);

#ifdef __cplusplus
}
#endif

#endif
