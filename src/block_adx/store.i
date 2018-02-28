#line 1 "store.c"

#line 1 "C:\\bitstream\\serv\\libcon\\base/std_def.h"




#line 1 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"





	
	
	typedef __int64				int64_t;
	typedef unsigned __int64	uint64_t;
	

	

#line 15 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
		
		
		
		
	#line 20 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
































#line 53 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"


typedef	void		   void_func();
typedef	void_func	   *void_func_ptr;





typedef enum
{
	NO_DECORATION = 0,
	MSVC_STDCALL_32 = 1,
	MSVC_CDECL_32 = 2,
	GCC_STDCALL_32 = 3,
	GCC_CDECL_32 = 4
}mod_name_decoration_t;




#line 75 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
#line 6 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	























#line 31 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	
	typedef unsigned int	size_t;
	typedef int64_t			ctime_t;

	typedef int				ptrdiff_t;
	


	

	
		
	#line 44 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	
	
		
		
		
		


		
		
		

		
		
		
		
		
		
		
		
	#line 65 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
#line 66 "C:\\bitstream\\serv\\libcon\\base/std_def.h"

typedef union
{
	struct {
		uint64_t	val;
	}uint64;
	struct {
		unsigned int ints[2];
	}uint32;
}large_uint_t;


#line 79 "C:\\bitstream\\serv\\libcon\\base/std_def.h"

#line 3 "store.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"


#line 4 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"

typedef void			*mem_ptr;
typedef const void		*const_mem_ptr;

typedef size_t		   mem_size;

struct big64
{
	union N
	{
		uint64_t v64;
		unsigned int v[2];
	}n;

	union N m;
};

struct big128
{
	unsigned int v[4];
};





		
__declspec(dllimport) mem_ptr		 memcpy_c				(mem_ptr dst_ptr,const_mem_ptr src_ptr,mem_size size);


__declspec(dllimport) mem_ptr		 memmove_c			(mem_ptr dst_ptr,const_mem_ptr src_ptr,mem_size size);
__declspec(dllimport) mem_ptr		 memset_c				(mem_ptr ptr,unsigned char v,mem_size size);
__declspec(dllimport) mem_ptr		 memset_32_c			(mem_ptr ptr,unsigned int v,mem_size size);
__declspec(dllimport) int			 memcmp_c				(const_mem_ptr ptr1,const_mem_ptr ptr2,size_t size);
__declspec(dllimport) const_mem_ptr	 memchr_c				(const_mem_ptr ptr,int value,mem_size size);
__declspec(dllimport) size_t			 memchr_32_c			(const_mem_ptr ptr,unsigned int value,mem_size size);
__declspec(dllimport) void			 qsort_c				(mem_ptr base, mem_size num, mem_size width,  int ( *comp)(const_mem_ptr,const_mem_ptr));

__declspec(dllimport) mem_ptr		 realloc_c			(mem_ptr ptr,mem_size sz);
__declspec(dllimport) void			 free_c				(mem_ptr ptr);
__declspec(dllimport) mem_ptr		 malloc_c				(mem_size sz);
__declspec(dllimport) mem_ptr		 calloc_c				(mem_size sz,mem_size blk);
__declspec(dllimport) mem_ptr		 get_next_aligned_ptr (mem_ptr ptr);

__declspec(dllimport) uint64_t		 mul64(uint64_t a, uint64_t b);
__declspec(dllimport) uint64_t		 muldiv64(uint64_t a, uint64_t b, uint64_t c);
__declspec(dllimport) uint64_t		 shl64(uint64_t a, unsigned char n);
__declspec(dllimport) uint64_t		 shr64(uint64_t a, unsigned char n);
__declspec(dllimport) double			 exp_c(double a);
__declspec(dllimport) void			 big128_mul(unsigned int x, struct big64 y, struct big128 *out);




__declspec(dllimport) unsigned int	__cdecl		compare_z_exchange_c(volatile unsigned int *data, unsigned int new_value);
__declspec(dllimport) unsigned int	__cdecl		compare_exchange_c  (volatile unsigned int *data,unsigned int value, unsigned int new_value);


__declspec(dllimport) char			__cdecl		fetch_add_c(volatile unsigned int *data, volatile char new_value);
__declspec(dllimport) char			__cdecl		mfence_c();


__declspec(dllimport) unsigned int	__cdecl		calc_crc32_c(const char *, size_t);









#line 77 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"



#line 4 "store.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/mem_base.h"









typedef struct
{
	volatile  mem_ptr zone;
}mem_zone_ref;

typedef struct
{
	const_mem_ptr zone;
}mem_zone_const_ref;

typedef mem_zone_ref			*mem_zone_ref_ptr;
typedef const mem_zone_ref		*mem_zone_ref_const_ptr;
typedef mem_zone_const_ref		*mem_zone_const_ref_ptr;

typedef int  zone_free_func(mem_zone_ref_ptr zone_ref, unsigned int scan_id);
typedef  zone_free_func	*zone_free_func_ptr;

typedef int  thread_func(mem_zone_ref_ptr p,unsigned int *status);
typedef thread_func *thread_func_ptr;

typedef enum {MEM_TYPE_DATA = 1,MEM_TYPE_TREE = 2}mem_area_type_t;
	
typedef int				vec_2s_t[2];
typedef unsigned int	vec_2_t[2];
typedef unsigned char	vec_4uc_t[4];

struct gfx_rect
{
	vec_2s_t	pos;
	vec_2_t		size;
};





__declspec(dllimport) void			 init_default_mem_area	(unsigned int size);
__declspec(dllimport) unsigned int	 mem_area_enable_sem		(unsigned int area_id);
__declspec(dllimport) unsigned int	 init_new_mem_area		(mem_ptr phys_start,	mem_ptr phys_end,mem_area_type_t type);
__declspec(dllimport) unsigned int	 free_mem_area			(unsigned int area_id);
__declspec(dllimport) unsigned int	 allocate_new_zone		(unsigned int area_id,	mem_size zone_size,	mem_zone_ref *zone_ref);
__declspec(dllimport) unsigned int	 allocate_new_empty_zone	(unsigned int area_id,mem_zone_ref *zone_ref);
__declspec(dllimport) int			 expand_zone				(mem_zone_ref *ref,mem_size new_size);
__declspec(dllimport) int 			 realloc_zone				(mem_zone_ref *zone_ref,mem_size new_size);
__declspec(dllimport) void 			 empty_trash				();
		
__declspec(dllimport) void			 copy_zone_ref			(mem_zone_ref_ptr dest_zone_ref,mem_zone_ref_const_ptr zone_ref);
__declspec(dllimport) void			 copy_zone_const_ref		(mem_zone_const_ref_ptr dest_zone_ref,mem_zone_const_ref_ptr zone_ref);
__declspec(dllimport) unsigned int	 get_zone_area_type		(mem_zone_ref_const_ptr zone);
__declspec(dllimport) unsigned int	 create_zone_ref			(mem_zone_ref *dest_zone_ref,mem_ptr ptr,mem_size size);
__declspec(dllimport) void			 init_mem_system			();
__declspec(dllimport) size_t			 dump_mem_used			(unsigned int area_id);
__declspec(dllimport) size_t			 dump_mem_used_after		(unsigned int area_id, unsigned int time, mem_zone_ref *outs, size_t nOuts);


__declspec(dllimport) int			  get_shared_slot			(mem_zone_ref_ptr shared_zone, mem_zone_ref_ptr *zone_ptr);
__declspec(dllimport) int			 release_shared_slot		(mem_zone_ref_ptr zone_ptr);

__declspec(dllimport) mem_ptr		 get_zone_ptr				(mem_zone_ref_const_ptr ref,mem_size ofset);
__declspec(dllimport) mem_size		 get_zone_size			(mem_zone_ref_const_ptr ref);
__declspec(dllimport) unsigned int	 do_mark_sweep			(unsigned int area_id, unsigned int delay);
__declspec(dllimport) void			 mark_zone				(mem_ptr zone, unsigned int scan_id);

__declspec(dllimport) unsigned int	 find_zones_used			(unsigned int area_id);
__declspec(dllimport) void			 do_gdt_real_mode			(mem_ptr new_gdt);
__declspec(dllimport) unsigned int	 get_zone_numref			(mem_zone_ref *zone_ref);
__declspec(dllimport) unsigned int	 area_type				(unsigned int area_id);

__declspec(dllimport) void			 swap_zone_ref					(mem_zone_ref_ptr dest_zone_ref, mem_zone_ref_ptr src_zone_ref);



__declspec(dllimport) int			 set_mem_area_id					(unsigned int area_id);
__declspec(dllimport) int			 set_tree_mem_area_id				(unsigned int area_id);
__declspec(dllimport) unsigned int	 get_mem_area_id					();
__declspec(dllimport) unsigned int	 get_tree_mem_area_id				();
__declspec(dllimport) int			 background_func					(thread_func_ptr func, mem_zone_ref_ptr params);


static __inline unsigned int mem_to_uint(const_mem_ptr ptr)
{
	return *((unsigned int *)&ptr);
}

static __inline unsigned short mem_to_ushort(const_mem_ptr ptr,unsigned char which)
{
	unsigned int ptr_val;
	unsigned int mask;
	unsigned short ret;
	mask	=	(0xFFFF<<which);
	ptr_val	=	*((unsigned int *)&ptr);
	ret		=	(unsigned short )((ptr_val&mask)>>which);
	return ret;
}

static __inline mem_size mem_to_size(const_mem_ptr ptr)
{
	return *((mem_size *)&ptr);
}

static __inline int mem_to_int(const_mem_ptr ptr)
{
	return *((int *)&ptr);
}


static __inline mem_ptr uint_to_mem(unsigned int val)
{
	large_uint_t val64;

	val64.uint32.ints[0]=val;
	val64.uint32.ints[1]=0;
	return ((mem_ptr )((mem_size)(val64.uint64.val)));
}

static __inline mem_ptr size_to_mem(size_t val)
{
	return ((mem_ptr )val);
}

static __inline mem_size mem_sub(const_mem_ptr base,const_mem_ptr end)
{
	mem_size	s_base,s_end;

	s_base	=	mem_to_uint(base);
	s_end	=	mem_to_uint(end);

	return (s_end-s_base);

}

static __inline mem_ptr mem_add(const_mem_ptr base,mem_size size)
{
	mem_size	s_base;

	s_base	=	mem_to_uint(base);
	s_base  =    s_base + size;
	return		size_to_mem(s_base);
}

static __inline mem_ptr mem_dec(const_mem_ptr base,mem_size size)
{
	mem_size	s_base;

	s_base	=	 mem_to_uint(base);
	s_base  =    s_base - size;
	return		size_to_mem(s_base);
}


static __inline void copy_vec4u_c	(vec_4uc_t d,const vec_4uc_t s)
{
	d[0]=s[0];
	d[1]=s[1];
	d[2]=s[2];
	d[3]=s[3];
}

__declspec(dllimport) void			  release_zone_ref	(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) void			  dec_zone_ref		(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) unsigned int   	inc_zone_ref		(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) mem_size	    	set_zone_free		(mem_zone_ref_ptr ref, zone_free_func_ptr	free_func);









#line 5 "store.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/std_str.h"




__declspec(dllimport) char *			 strncpy_c				(char *string,const char *src_string,size_t		 cnt);
__declspec(dllimport) char *			 strncpy_cs				(char *string,size_t str_len,const char *src_string,size_t cnt);

__declspec(dllimport) int			 strcpy_cs				(char *string,size_t size,const char *src_string);
__declspec(dllimport) char *			 strcpy_c					(char *string,const char *src_string);
__declspec(dllimport) int			 strcat_cs				(char *string,size_t size,const char *src_string);
__declspec(dllimport) int			 strcat_intval_s			(char *string,size_t size,const char *name,int val,int radix);
__declspec(dllimport) int			 strcat_uintval_s			(char *string,size_t size,const char *name,unsigned int val,int radix);
__declspec(dllimport) int			 strcat_escaped_s			(char *string,size_t size,const char *src_string);
__declspec(dllimport) char *			 str_replace_char_c		(char *string, char c1, char c2);
__declspec(dllimport) int			 strncat_c				(char *string,const char *src_string,size_t max);
__declspec(dllimport) int			 strcat_c					(char *string,const char *src_string);
__declspec(dllimport) int			 strcmp_c					(const char *string1,const char *string2);
__declspec(dllimport) int			 strncmp_c				(const char *string1,const char *string2,size_t len);
__declspec(dllimport) int			 strincmp_c				(const char *string1,const char *string2,size_t len);
__declspec(dllimport) int			 stricmp_c				(const char *string1,const char *string2);

__declspec(dllimport) const char	*	 strrchr_c				(const char *src,int car);
__declspec(dllimport) size_t 		 strlen_c					(const char *string);
__declspec(dllimport) size_t			 strlpos_c				(const char *string,size_t ofset,char c);
__declspec(dllimport) size_t			 strrpos_c				(const char *string,char c);

__declspec(dllimport) int			 itoa_s					(int value, char *string,size_t len, int radix);
__declspec(dllimport) int			 uitoa_s					(size_t value, char *string, size_t len, int radix);
__declspec(dllimport) int			 luitoa_s					(uint64_t value, char *string, size_t len, int radix);
__declspec(dllimport) int			 litoa_s					(int64_t value, char *str, size_t len, int base);

__declspec(dllimport) long			 strtol_c					(const char *nptr, char **endptr,int base);
__declspec(dllimport) int64_t		 strtoll_c				(const char *nptr, char **endptr, int base);
__declspec(dllimport) unsigned long	 strtoul_c				(const char *nptr, char **endptr, int base);
__declspec(dllimport) short			 strtos_c					(const char *nptr, char **endptr, int base);
__declspec(dllimport) long			 atol_c					(const char *str ); 
__declspec(dllimport) void			 dtoll_c					(double dAmount, uint64_t *nAmount);
__declspec(dllimport) const char *	 strstr_c					(const char *buf, const char *sub);
__declspec(dllimport) unsigned int	 get_new_kern_log_id		(const char *pref,unsigned char color);
__declspec(dllimport) void			 kernel_log				(unsigned int kern_log_id,const char *str);
__declspec(dllimport) int			 tolower_c				(int _c);
__declspec(dllimport) int			 toupper_c				(int _c);
__declspec(dllimport) int			 isprint_c				(int _c);
__declspec(dllimport) int			 isalpha_c				(int _c);
__declspec(dllimport) int			 isdigit_c				(int _c);
__declspec(dllimport) int			 isdigit_c				(int _c);
__declspec(dllimport) int			 isxdigit_c				(int _c);
__declspec(dllimport) int			 isspace_c				(int _c);
__declspec(dllimport) void			 snooze_c					(unsigned int micro_sec);
__declspec(dllimport) void			 dtoa_c					(char *buff, char conv, int bsize, int dplace, double value);
__declspec(dllimport) unsigned int	 parseDate				(const char *date);
__declspec(dllimport) void			 store_bigendian			(unsigned char *x, uint64_t u);
__declspec(dllimport) uint64_t		 load_bigendian			(const unsigned char *x);

__declspec(dllimport) void			 strtod_c					(const char *str, double *d);
__declspec(dllimport) void			 strtof_c					(const char *str, float *f);

static const char		hex_chars[]		=	{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

typedef unsigned char	ipv4_t[4];
typedef	char			bitcore_cmd_t[12];
typedef	unsigned char	hash_t[32];
typedef	char			btc_addr_t[34];
typedef	char			btc_paddr_t[52];

#line 6 "store.c"

#line 1 "C:\\bitstream\\serv\\libcon\\include\\mem_stream.h"




typedef struct
{
	mem_zone_ref		data;
	mem_size			current_ptr;
	mem_size			buf_ofs;
}mem_stream;

typedef struct
{
	mem_zone_const_ref		data;
	mem_size				current_ptr;
}const_mem_stream;


__declspec(dllimport) void				mem_stream_init(mem_stream *stream, mem_zone_ref *stream_zone, mem_size buffer_ofset);
__declspec(dllimport) int				mem_stream_decomp(mem_stream *stream, unsigned int comp_size, unsigned int decomp_size);
__declspec(dllimport) unsigned char		mem_stream_read_8(mem_stream *stream);
__declspec(dllimport) unsigned char		mem_stream_peek_8(mem_stream *stream);
__declspec(dllimport) unsigned short		mem_stream_read_16(mem_stream *stream);
__declspec(dllimport) unsigned int		mem_stream_read_32(mem_stream *stream);
__declspec(dllimport) unsigned int		mem_stream_peek_32(mem_stream *stream);
__declspec(dllimport) size_t				mem_stream_read(mem_stream *stream, char *data, size_t len);
__declspec(dllimport) size_t				mem_stream_skip(mem_stream *stream, unsigned int len);
__declspec(dllimport) size_t				mem_stream_skip_to(mem_stream *stream, size_t position);
__declspec(dllimport) size_t				mem_stream_write(mem_stream *stream, unsigned char *data, size_t len);
__declspec(dllimport) size_t				mem_stream_write_8(mem_stream *stream, unsigned char data);
__declspec(dllimport) size_t				mem_stream_write_16(mem_stream *stream, unsigned short data);
__declspec(dllimport) size_t				mem_stream_write_32(mem_stream *stream, unsigned int data);
__declspec(dllimport) size_t				mem_stream_get_pos(mem_stream *stream);

__declspec(dllimport) void				mem_stream_close(mem_stream *stream);

__declspec(dllimport) int			  get_file_to_memstream(const char *path, mem_stream *stream);
#line 8 "store.c"

#line 1 "C:\\bitstream\\serv\\libbase\\include\\sha256.h"

	
#line 4 "C:\\bitstream\\serv\\libbase\\include\\sha256.h"

typedef struct
{
	unsigned int total[2];      
	unsigned int state[8];      
	unsigned char buffer[64];   
	int is224;                  
}
mbedtls_sha256_context;

__declspec(dllimport) void  mbedtls_sha256_init(mbedtls_sha256_context *ctx);
__declspec(dllimport) void  mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224);
__declspec(dllimport) void  mbedtls_sha256_update(mbedtls_sha256_context *ctx, const unsigned char *input, size_t ilen);
__declspec(dllimport) void  mbedtls_sha256_free(mbedtls_sha256_context *ctx);
__declspec(dllimport) void  mbedtls_sha256_finish(mbedtls_sha256_context *ctx, unsigned char output[32]);
__declspec(dllimport) void  mbedtls_sha256(const unsigned char *input, size_t ilen, unsigned char output[32], int is224);
__declspec(dllimport) int	  crypto_hash_sha512(unsigned char *out, const unsigned char *in, size_t inlen);
__declspec(dllimport) int	  ripemd160(const void* in, unsigned long length, void* out);
#line 10 "store.c"

#line 1 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"


#line 4 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"







typedef unsigned char dh_key_t[64];

typedef int				 crypto_extract_key_func	(dh_key_t pk, const dh_key_t sk);
typedef int 			 crypto_sign_open_func	(const struct string *sign, struct string *msg, const struct string *pk);

typedef crypto_sign_open_func	*crypto_sign_open_func_ptr;
typedef crypto_extract_key_func *crypto_extract_key_func_ptr;


	typedef struct string	 crypto_sign_func(const struct string *msg, const dh_key_t sk);
	typedef crypto_sign_func		*crypto_sign_func_ptr;
#line 23 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"



#line 12 "store.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\strs.h"

struct string
{
	char	*str;		
	size_t  len;		
	size_t  size;		
};


struct host_def
{
	struct string		host;		
	struct string		port_str;	
	unsigned short		port;		
};



__declspec(dllimport)		void				 init_string			(struct string *str);


__declspec(dllimport)		int 				 prepare_new_data		(struct string *str, size_t len);


__declspec(dllimport)		int					 clone_string			(struct string *str, const struct string *str1);


__declspec(dllimport)		int					 make_string			(struct string *str, const char *toto);


__declspec(dllimport)		int 				 make_string_l		(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_url		(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_from_url	(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_from_uint(struct string *str, size_t i);


__declspec(dllimport)		size_t				 cat_string			(struct string *str, const struct string *src);


__declspec(dllimport)		int					 strcat_uint			(struct string *str, size_t i);


__declspec(dllimport)		int					 strcat_float			(struct string *str, double f);


__declspec(dllimport)		int 				 strcat_int			(struct string *str, int i);


__declspec(dllimport)		int 				 cat_cstring			(struct string *str, const char *src);


__declspec(dllimport)		int 				 cat_ncstring			(struct string *str, const char *src, size_t src_len);


__declspec(dllimport)		int					 cat_ncstring_p		(struct string *str, const char *src, size_t src_len);


__declspec(dllimport)		int					 cat_cstring_p		(struct string *str, const char *src);


__declspec(dllimport)		int 				 make_cstring			(const struct string *str, char *toto, size_t len);


__declspec(dllimport)		void				 free_string			(struct string *str);


__declspec(dllimport)		struct host_def *	 make_host_def		(const char *host, unsigned short port);


__declspec(dllimport)		struct host_def	*	 make_host_def_url	(const struct string *url, struct string *path);


__declspec(dllimport)		void				 copy_host_def		(struct host_def *dhost, const struct host_def *host);


__declspec(dllimport)		void				 free_host_def		(struct host_def *host);


__declspec(dllimport)		void				 cat_tag				(struct string *str, const char *tag, const char *val);


__declspec(dllimport)		int					 do_zip				(const char *fileName, struct string *initial_data, const char **files, size_t nFiles, struct string *zipData);


__declspec(dllimport)		int					 str_end_with			(const struct string *str, const char *end);

__declspec(dllimport)		int					 str_start_with		(const struct string *str, const char *start);

__declspec(dllimport)		int					 vstr_to_str			(mem_ptr data_ptr, struct string *str);


__declspec(dllimport)		int					 find_mem_hash		(hash_t hash, unsigned char *mem_hash, unsigned int num);
#line 13 "store.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\tree.h"
































































































































const enum op_type { CMP_E, CMP_L, CMP_G, CMPL_E, CMPL_L, CMPL_G, CMPL_N, CMP_N };

struct key_val
{
	char			key[64];
	unsigned int	kcrc;
	enum op_type	op;
	struct string	value;
};

struct node_hash_val_t
{
	unsigned int		crc;
	mem_ptr				data;
};






































































































































#line 14 "store.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\fsio.h"




__declspec(dllimport) size_t			 file_size(const char *path);
__declspec(dllimport) int			 append_file(const char *path, const void *data, size_t data_len);
__declspec(dllimport) int			 truncate_file(const char *path, size_t ofset, const void *data, size_t data_len);
__declspec(dllimport) int			 stat_file(const char *path);
__declspec(dllimport) int			 create_dir(const char *path);
__declspec(dllimport) int			 del_dir(const char *path);
__declspec(dllimport) int			 put_file(const char *path, void *data, size_t data_len);
__declspec(dllimport) int			 get_sub_dirs(const char *path, struct string *dir_list);
__declspec(dllimport) int			 get_sub_files(const char *path, struct string *file_list);
__declspec(dllimport) int			 get_file(const char *path, unsigned char **data, size_t *data_len);
__declspec(dllimport) int			 get_file_len(const char *path, size_t size, unsigned char **data, size_t *data_len);
__declspec(dllimport) int			 get_file_chunk(const char *path, size_t ofset, unsigned char **data, size_t *data_len);

__declspec(dllimport) int			 get_hash_idx(const char *path, size_t idx, hash_t hash);
__declspec(dllimport) int			 set_home_path(const char *name);
__declspec(dllimport) int			 set_data_dir(const struct string *path,const char *name);
__declspec(dllimport) int			 set_exe_path();
__declspec(dllimport) int			 get_exe_path(struct string *outPath);
__declspec(dllimport) int			 daemonize(const char *name);
__declspec(dllimport) ctime_t		 get_time_c(void);
__declspec(dllimport) void			 get_system_time_c(ctime_t *time);
__declspec(dllimport) void			 console_print(const char *msg);
__declspec(dllimport) int			 log_output(const char *data);
__declspec(dllimport) int			 set_mem_exe(mem_zone_ref_ptr zone);
__declspec(dllimport) int			 move_file(const char *ipath,const char *opath);
__declspec(dllimport) int			 del_file(const char *path);
__declspec(dllimport) int			 set_ftime(const char *path, ctime_t time);
__declspec(dllimport) int			 get_ftime(const char *path, ctime_t *time);
__declspec(dllimport) int			 get_home_dir(struct string *path);
__declspec(dllimport) int			 set_cwd(const char *path);
__declspec(dllimport) int			 get_cwd(char *path, size_t len);
__declspec(dllimport) int			 rm_dir(const char *dir);
__declspec(dllimport) unsigned int	 get_tree_mem_area_id(void);
__declspec(dllimport) unsigned int	 get_mem_area_id(void);
__declspec(dllimport) unsigned int	 isRunning(void);
__declspec(dllimport) int  default_RNG(unsigned char *dest, size_t size);
#line 15 "store.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\parser.h"




__declspec(dllimport) int	 load_script				(const char *file,const char *name, mem_zone_ref_ptr script_vars,unsigned int opts);
__declspec(dllimport) int	 get_script_var_value_str (mem_zone_ref_ptr global_vars, const char *var_path, struct string *out, unsigned int radix);
__declspec(dllimport) int	 get_script_var_value_i32 (mem_zone_ref_ptr global_vars, const char *var_path, unsigned int *out);
__declspec(dllimport) int	 get_script_var_value_ptr	(mem_zone_ref_ptr global_vars, const char *var_path, mem_ptr *out);
__declspec(dllimport) int	 resolve_script_var(mem_zone_ref_ptr global_vars, mem_zone_ref_ptr script_proc, const char *var_path, unsigned int var_type, mem_zone_ref_ptr out_var, mem_zone_ref_ptr pout_var);
__declspec(dllimport) int	 execute_script_proc		(mem_zone_ref_ptr global_vars, mem_zone_ref_ptr script_proc);
__declspec(dllimport) int	 load_mod_def				(mem_zone_ref_ptr mod_def);

#line 16 "store.c"



#line 1 "c:\\bitstream\\serv\\block_adx\\block_api.h"




struct bin_tree;
typedef struct bin_tree node;









__declspec(dllexport)  int	 init_blocks(mem_zone_ref_ptr node_config);


__declspec(dllexport)  void	 mul_compact(unsigned int nBits, uint64_t op, hash_t hash);


__declspec(dllexport)  int	 cmp_hashle(hash_t hash1, hash_t hash2);


__declspec(dllexport) unsigned int	 calc_new_target(unsigned int nActualSpacing, unsigned int TargetSpacing, unsigned int nTargetTimespan, unsigned int pBits);


__declspec(dllexport)  int	 get_block_height();


__declspec(dllexport)  int	 get_blockreward(uint64_t block, uint64_t *block_reward);


__declspec(dllexport)  int	 get_hash_list(mem_zone_ref_ptr hdr_list, mem_zone_ref_ptr hash_list);


__declspec(dllexport)  int	 build_merkel_tree(mem_zone_ref_ptr txs, hash_t merkleRoot);


__declspec(dllexport)  int	 make_genesis_block(mem_zone_ref_ptr genesis_conf, mem_zone_ref_ptr genesis_blk);


__declspec(dllexport) int	   get_tx_output(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vout);


__declspec(dllexport)  int	   get_insig_info(const struct string *script, struct string *sign, struct string *pubk, unsigned char *hash_type);


__declspec(dllexport)  int	   parse_sig_seq(const struct string *sign_seq, struct string *sign, unsigned char *hashtype, int rev);


__declspec(dllexport)  int		serialize_script(mem_zone_ref_const_ptr script_node, struct string *script);


__declspec(dllexport)  int		create_null_tx(mem_zone_ref_ptr tx, unsigned int time, unsigned int block_height);


__declspec(dllexport)  int		is_tx_null(mem_zone_ref_const_ptr tx);


__declspec(dllexport)  int		is_vout_null(mem_zone_ref_const_ptr tx, unsigned int idx);


__declspec(dllexport)  int		new_transaction(mem_zone_ref_ptr tx, ctime_t time);


__declspec(dllexport)  int		 tx_add_output(mem_zone_ref_ptr tx, uint64_t value, const struct string *script);


__declspec(dllexport)  int		tx_add_input(mem_zone_ref_ptr tx, const hash_t tx_hash, unsigned int index,const struct string *script);


__declspec(dllexport)  int		create_payment_script(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node);


__declspec(dllexport) int		create_payment_script_data(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllexport)  int		create_p2sh_script			(btc_addr_t addr, mem_zone_ref_ptr script_node);


__declspec(dllexport)  int		create_p2sh_script_byte		(btc_addr_t addr, mem_zone_ref_ptr script_node, unsigned char val);

__declspec(dllexport)  int		create_p2sh_script_data		(btc_addr_t addr, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllexport)  int		compute_tx_sign_hash		(mem_zone_ref_const_ptr tx, unsigned int nIn, const struct string *script, unsigned int hash_type, hash_t txh);


__declspec(dllexport)  int		check_tx_input_sig			(mem_zone_ref_const_ptr tx, unsigned int nIn, struct string *vpubK);


__declspec(dllexport)  int		check_tx_outputs			(mem_zone_ref_ptr tx, uint64_t *total, unsigned int *is_staking);


__declspec(dllexport)  int		check_tx_inputs				(mem_zone_ref_ptr tx, uint64_t *total_in, unsigned int *is_coinbase,unsigned int check_sig);



__declspec(dllexport)  int	 check_block_pow				(mem_zone_ref_ptr hdr, hash_t diff_hash);


__declspec(dllexport)  int	 check_block_sign				(const struct string *sign, const hash_t hash, const struct string *pubk);


__declspec(dllexport)  int	 get_tx_input_hash			(mem_zone_ref_ptr tx, unsigned int idx, hash_t hash);


__declspec(dllexport)  int	 get_tx_output_amount			(mem_zone_ref_ptr tx, unsigned int idx, uint64_t *amount);


__declspec(dllexport)  int	 get_tx_output_addr			(const hash_t tx_hash, unsigned int idx, btc_addr_t addr);


__declspec(dllexport)  int	 tx_sign						(mem_zone_ref_const_ptr tx, unsigned int nIn, unsigned int hashType, const struct string *sign, const struct string *inPubKey);


__declspec(dllexport) int		compute_block_hash			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllexport) int		compute_block_pow			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllexport)  int	 block_compute_pow_target		(mem_zone_ref_ptr ActualSpacing, mem_zone_ref_ptr diff);


__declspec(dllexport)  int	 compute_tx_hash				(mem_zone_ref_ptr tx, hash_t hash);


__declspec(dllexport) int		get_block_version			(unsigned int *v);


__declspec(dllexport) int		blk_check_sign				(const struct string *sign, const struct string *pubk, const hash_t hash);


__declspec(dllexport)  int	 check_tx_list				(mem_zone_ref_ptr tx_list, uint64_t block_reward,hash_t merkle,unsigned int check_sig);



__declspec(dllexport)  int	 find_inputs					(mem_zone_ref_ptr tx_list, hash_t txid, unsigned int oidx);


__declspec(dllexport) int		get_tx_input				(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vin);



__declspec(dllexport) unsigned int	 SetCompact			(unsigned int bits, hash_t out);



__declspec(dllexport) int  check_utxo						(const char *tx, unsigned int oidx);


__declspec(dllexport) int  dump_tx_infos					(mem_zone_ref_ptr tx);
__declspec(dllexport) int  dump_txh_infos					(const char *hash);


__declspec(dllexport)  int	 get_block_tree				(node **blktree);

__declspec(dllexport)  int	 get_tx_data					(mem_zone_ref_ptr tx, mem_zone_ref_ptr txData);

__declspec(dllexport)  int	 blk_find_last_pow_block		(mem_zone_ref_ptr pindex, unsigned int *block_time);
__declspec(dllexport)  int	 block_pow					(uint64_t height);
__declspec(dllexport)  int	 extract_key					(dh_key_t priv, dh_key_t pub);
__declspec(dllexport)  int	 remove_tx_index				(hash_t tx_hash);

__declspec(dllexport) int  set_root_app					(mem_zone_ref_ptr tx);
__declspec(dllexport) int  get_root_app					(mem_zone_ref_ptr  rootAppHash);
__declspec(dllexport) int  get_apps						(mem_zone_ref_ptr Apps);

__declspec(dllexport) int  get_root_app_addr				(mem_zone_ref_ptr rootAppAddr);

__declspec(dllexport) int  is_app_root					(mem_zone_ref_ptr tx);

__declspec(dllexport) int  blk_load_app_root				();

__declspec(dllexport) int  blk_load_apps					(mem_zone_ref_ptr apps);

__declspec(dllexport) int  make_approot_tx				(mem_zone_ref_ptr tx, ctime_t time,btc_addr_t addr);

__declspec(dllexport) int  get_root_app_fee				(mem_zone_ref_ptr rootAppFees);

__declspec(dllexport) int  make_app_tx					(mem_zone_ref_ptr tx,const char *app_name,btc_addr_t appAddr);
__declspec(dllexport) int  make_app_item_tx				(mem_zone_ref_ptr tx, const struct string *app_name, unsigned int item_id);
__declspec(dllexport) int  parse_approot_tx				(mem_zone_ref_ptr tx);


__declspec(dllexport)  int   get_app_name					(const struct string *script, struct string *app_name);
__declspec(dllexport)  int   get_app_types				(mem_zone_ref_ptr app, mem_zone_ref_ptr types);
__declspec(dllexport)  int   get_app_scripts				(mem_zone_ref_ptr app, mem_zone_ref_ptr scripts);

__declspec(dllexport)  int	 get_type_infos				(struct string *script, char *name, unsigned int *id, unsigned int *flags);

__declspec(dllexport)  int	 get_tx_file					(mem_zone_ref_ptr tx, mem_zone_ref_ptr hash_list);
__declspec(dllexport)  int	 tx_is_app_file				(mem_zone_ref_ptr tx, struct string *appName, mem_zone_ref_ptr file);
__declspec(dllexport)  int	 get_app_type_key				(const char *appName, unsigned int type_id, const char *kname, unsigned int *ktype, unsigned int *flags);
__declspec(dllexport)  int	 get_app_type_idxs			(const char *appName, unsigned int type_id, mem_zone_ref_ptr keys);
__declspec(dllexport)  int	 load_obj_type				(const char *app_name, const char *objHash, unsigned int *type_id, btc_addr_t objAddr);
__declspec(dllexport)  int	 check_app_obj_unique			(const char *appName, unsigned int type_id, mem_zone_ref_ptr obj);









__declspec(dllexport) int    get_out_script_address(const struct string *script, struct string *pubk, btc_addr_t addr);


__declspec(dllexport) int    get_out_script_return_val(const struct string *script, struct string *data);


__declspec(dllexport) int    get_tx_output_script(const hash_t tx_hash, unsigned int idx, struct string *script, uint64_t *amount);


__declspec(dllexport) void    key_to_hash(const unsigned char *pkey, unsigned char *keyHash);


__declspec(dllexport) void   key_to_addr(const unsigned char *pkey, btc_addr_t addr);


__declspec(dllexport) void    paddr_to_key(btc_paddr_t addr, dh_key_t key);


__declspec(dllexport) int    make_script_file(mem_zone_ref_ptr file, struct string *pKey, struct string *sign, mem_zone_ref_ptr script);

__declspec(dllexport) int    make_script_layout(mem_zone_ref_ptr file, mem_zone_ref_ptr script);

__declspec(dllexport) int    make_script_module(mem_zone_ref_ptr file, mem_zone_ref_ptr script);






__declspec(dllexport) int   get_moneysupply(uint64_t *amount);


__declspec(dllexport) int  get_last_block_height();


__declspec(dllexport) int   find_blk_hash(const hash_t tx_hash, hash_t blk_hash,uint64_t *height,unsigned int *ofset,unsigned int *tx_time);


__declspec(dllexport) int   find_hash(hash_t hash);


__declspec(dllexport) int   find_index_hash(hash_t h);


__declspec(dllexport) int   load_blk_hdr(mem_zone_ref_ptr hdr, const char *blk_hash);


__declspec(dllexport) int   get_blk_height(const char *blk_hash, uint64_t *height);


__declspec(dllexport) int   get_tx_blk_height(const hash_t tx_hash, uint64_t *height, uint64_t *block_time, unsigned int *tx_time);


__declspec(dllexport) int   is_pow_block(const char *blk_hash);


__declspec(dllexport) int   store_block(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllexport) int   blk_load_tx_ofset(const char *blk_hash, unsigned int ofset, mem_zone_ref_ptr tx);


__declspec(dllexport) int   load_tx(mem_zone_ref_ptr tx, hash_t blk_hash, const hash_t tx_hash);


__declspec(dllexport) int   load_tx_input(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr	vin, mem_zone_ref_ptr tx_out);


__declspec(dllexport) int   load_blk_tx_input(const char *blk_hash, unsigned int tx_ofset, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllexport) int   load_tx_output_amount(const hash_t tx_hash, unsigned int idx, uint64_t *amount);


__declspec(dllexport) int   load_tx_input_vout(mem_zone_ref_const_ptr tx, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllexport) int   load_tx_addresses(btc_addr_t addr, mem_zone_ref_ptr tx_hashes);


__declspec(dllexport) int   load_obj(const char *app_name, const char *objHash, const char *objName, unsigned int opts, mem_zone_ref_ptr obj, btc_addr_t objAddr);


__declspec(dllexport) int   load_obj_childs(const char *app_name, const char *objHash, const char *KeyName, size_t first, size_t max, unsigned int opts, mem_zone_ref_ptr objs);


__declspec(dllexport) int   make_app_child_obj_tx(mem_zone_ref_ptr tx, const char *app_name, hash_t objHash, const char *keyName, unsigned int ktype,hash_t childHash);


__declspec(dllexport) int   get_app_obj_hashes(const char *app_name, mem_zone_ref_ptr hash_list);


__declspec(dllexport) int  get_app_type_last_objs_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);


__declspec(dllexport) int   get_block_size(const char *blk_hash, size_t *size);


__declspec(dllexport) int   get_blk_tx_hash(const char* blk_hash, unsigned int idx, hash_t tx_hash);


__declspec(dllexport) int   get_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs, size_t max);


__declspec(dllexport) unsigned int   get_blk_ntxs(const char* blk_hash);


__declspec(dllexport) int   load_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs);


__declspec(dllexport) int   get_block_time(const char *blkHash, ctime_t *time);


__declspec(dllexport) int   store_tx_inputs(mem_zone_ref_ptr tx);


__declspec(dllexport) int   store_tx_outputs(mem_zone_ref_ptr tx);


__declspec(dllexport) int   store_tx_addresses(btc_addr_t addr, hash_t tx_hash);


__declspec(dllexport) int   remove_tx_addresses(const btc_addr_t addr, const hash_t tx_hash);


__declspec(dllexport) int   remove_tx(hash_t tx_hash);


__declspec(dllexport)  int	 load_block_indexes(mem_zone_ref_ptr hdr_list);


__declspec(dllexport)  int	 store_tx_blk_index(const hash_t tx_hash, const hash_t blk_hash,uint64_t height,size_t tx_ofset,unsigned int time);


__declspec(dllexport) int   store_block_txs(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllexport)  int	 clear_tx_index();


__declspec(dllexport)  int	 get_app_type_obj_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);
__declspec(dllexport)  int	 get_app_type_nobjs(const char *app_name, unsigned int type_id);
__declspec(dllexport)  int	 get_app_file(mem_zone_ref_ptr file_tx, struct string *app_name, mem_zone_ref_ptr file);
__declspec(dllexport)  int	 get_appfile_tx(const char *app_name, hash_t fileHash, hash_t txHash);
__declspec(dllexport)  int	 has_app_file(struct string *app_name, hash_t fileHash);
__declspec(dllexport)  int	 get_app_files(struct string *app_name, size_t first, size_t num, mem_zone_ref_ptr files);
__declspec(dllexport)  int	 get_app_missing_files(struct string *app_name, mem_zone_ref_ptr pending, mem_zone_ref_ptr files);





typedef int  get_blk_staking_infos_func	(mem_zone_ref_ptr blk, const char *blk_hash, mem_zone_ref_ptr infos);
typedef int	 store_tx_staking_func		(mem_zone_ref_ptr tx, hash_t tx_hash, btc_addr_t stake_addr, uint64_t	stake_in);
typedef int	 get_tx_pos_hash_data_func	(mem_zone_ref_ptr hdr, const hash_t txHash, unsigned int OutIdx, struct string *hash_data, uint64_t *amount, hash_t out_diff);
typedef int	 get_target_spacing_func		(unsigned int *target);
typedef int	 get_stake_reward_func		(uint64_t height, uint64_t *reward);
typedef int	 get_last_stake_modifier_func	(mem_zone_ref_ptr pindex, hash_t nStakeModifier, unsigned int *nModifierTime);
typedef int	 compute_tx_pos_func			(mem_zone_ref_ptr tx, hash_t StakeModifier, unsigned int txTime, hash_t pos_hash, uint64_t *weight);
typedef int	 create_pos_block_func		(hash_t pHash, mem_zone_ref_ptr tx, mem_zone_ref_ptr newBlock);
typedef int	 check_tx_pos_func			(mem_zone_ref_ptr blk, mem_zone_ref_ptr tx);
typedef int	 get_min_stake_depth_func		(unsigned int *depth);
typedef unsigned int 	get_current_pos_difficulty_func();

typedef get_blk_staking_infos_func		*get_blk_staking_infos_func_ptr;
typedef store_tx_staking_func			*store_tx_staking_func_ptr;
typedef get_tx_pos_hash_data_func		*get_tx_pos_hash_data_func_ptr;
typedef get_target_spacing_func			*get_target_spacing_func_ptr;
typedef get_stake_reward_func			*get_stake_reward_func_ptr;
typedef get_last_stake_modifier_func	*get_last_stake_modifier_func_ptr;
typedef compute_tx_pos_func				*compute_tx_pos_func_ptr;
typedef create_pos_block_func			*create_pos_block_func_ptr;
typedef check_tx_pos_func				*check_tx_pos_func_ptr;
typedef get_min_stake_depth_func		*get_min_stake_depth_func_ptr;
typedef get_current_pos_difficulty_func	*get_current_pos_difficulty_func_ptr;
#line 20 "store.c"



__declspec(dllimport) size_t				compute_payload_size(mem_zone_ref_ptr payload_node);
__declspec(dllimport) char*				write_node(mem_zone_ref_const_ptr key, unsigned char *payload);
__declspec(dllimport) size_t				get_node_size(mem_zone_ref_ptr key);
__declspec(dllimport) void				serialize_children(mem_zone_ref_ptr node, unsigned char *payload);
__declspec(dllimport) const unsigned char*	 read_node(mem_zone_ref_ptr key, const unsigned char *payload,size_t len);
__declspec(dllimport) size_t			 init_node(mem_zone_ref_ptr key);


extern int tx_is_app_item(hash_t txh, unsigned int oidx, mem_zone_ref_ptr app_tx, unsigned char *val);
extern int tx_is_app_child(hash_t txh, unsigned int oidx,struct string *app_name);
extern int add_app_tx(mem_zone_ref_ptr new_app, const char *app_name);
extern int get_script_data(const struct string *script, size_t *offset, struct string *data);
extern int get_script_file(struct string *script, mem_zone_ref_ptr file);
extern int obj_new(mem_zone_ref_ptr type, const char *objName, struct string *script, mem_zone_ref_ptr obj);
extern int add_app_tx_type(mem_zone_ref_ptr app, mem_zone_ref_ptr typetx);
extern int add_app_script(mem_zone_ref_ptr app, mem_zone_ref_ptr script);


extern hash_t		null_hash;
extern unsigned int	has_root_app;
extern btc_addr_t	root_app_addr;
extern hash_t		app_root_hash;
extern mem_zone_ref	apps;

btc_addr_t			src_addr_list[1024] = { 0xABCDEF };

static __inline void make_blk_path(const char *chash, struct string *blk_path)
{

	make_string		(blk_path, "blks");
	cat_ncstring_p	(blk_path, chash + 0, 2);
	cat_ncstring_p	(blk_path, chash + 2, 2);
	cat_cstring_p	(blk_path, chash);
}

static __inline void get_utxo_path(const char *txh,unsigned int oidx,struct string *tx_path)
{
	make_string		(tx_path, "utxos");
	cat_ncstring_p	(tx_path, txh + 0, 2);
	create_dir		(tx_path->str);
	cat_ncstring_p	(tx_path, txh + 2, 2);
	create_dir		(tx_path->str);
	cat_ncstring_p	(tx_path, txh,64);
	cat_cstring		(tx_path, "_out_");
	strcat_int		(tx_path, oidx);
}

__declspec(dllexport) int  get_last_block_height()
{
	return file_size("blk_indexes") / 32;
}

__declspec(dllexport) int  find_index_hash(hash_t h)
{
	unsigned char *buffer;
	size_t		  len;
	int				ret = 0;

	if (get_file("blk_indexes", &buffer, &len) > 0)
	{
		size_t cur = 0;
		while (cur < len)
		{
			if (!memcmp_c(buffer + cur, h, sizeof(hash_t)))
			{
				ret = 1;
				break;
			}

			cur += 32;
		}

		free_c(buffer);
	}


	return ret;
}


__declspec(dllexport) int  get_moneysupply(uint64_t *amount)
{
	unsigned char *data;
	size_t len;
	int ret = 0;
	if (get_file("supply", &data, &len)>0)
	{
		if (len >= sizeof(uint64_t))
		{
			ret = 1;
			*amount = *((uint64_t *)data);
		}
		free_c(data);
	}
	return ret;

}



__declspec(dllexport) int  find_hash(hash_t hash)
{
	char				file_name[65];
	struct string		blk_path = { (void *)0x00000000L };
	unsigned int		n;
	int					ret;

	n = 32;
	while (n--)
	{
		file_name[n * 2 + 0] = hex_chars[hash[n] >> 4];
		file_name[n * 2 + 1] = hex_chars[hash[n] & 0x0F];
	}
	file_name[64] = 0;

	make_blk_path	(file_name,&blk_path);
	cat_cstring		(&blk_path, "_blk");

	ret = (stat_file(blk_path.str) == 0) ? 1 : 0;

	free_string(&blk_path);
	return ret;
}





__declspec(dllexport) int  blk_load_tx_ofset(const char *blk_hash, unsigned int ofset, mem_zone_ref_ptr tx)
{
	struct string		tx_path = { 0 };
	unsigned char		*tx_data;
	size_t				tx_data_len;
	int					ret;

	make_string		(&tx_path, "blks");
	cat_ncstring_p	(&tx_path, blk_hash + 0, 2);
	cat_ncstring_p	(&tx_path, blk_hash + 2, 2);
	cat_cstring_p	(&tx_path, blk_hash);
	cat_cstring		(&tx_path, "_txs");

	ret = 0;
	if (get_file_chunk(tx_path.str,ofset, &tx_data, &tx_data_len) > 0)
	{
		if ((tx->zone != (void *)0x00000000L) || (tree_manager_create_node("tx", 0x0B008000, tx)))
		{
			hash_t tmph,txh;

			init_node		(tx);
			read_node		(tx, tx_data,tx_data_len);

			mbedtls_sha256	(tx_data, tx_data_len, tmph,0);
			mbedtls_sha256	(tmph, 32, txh,0);

			tree_manager_set_child_value_i32 (tx,"size",tx_data_len);
			tree_manager_set_child_value_hash(tx,"txid",txh);
			ret = 1;
		}
		free_c(tx_data);
	}
	free_string(&tx_path);

	return ret;
}

__declspec(dllexport) int  load_tx(mem_zone_ref_ptr tx, hash_t blk_hash, const hash_t tx_hash)
{
	hash_t				th;
	char				chash[65], cthash[65];
	struct string		tx_path = { 0 };
	unsigned char		*buffer;
	mem_size			size;
	int					ret = 0;

	unsigned int		n = 32,ofset;

	while (n--)
	{
		cthash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
		cthash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];

		chash[n * 2 + 0] = hex_chars[tx_hash[31-n] >> 4];
		chash[n * 2 + 1] = hex_chars[tx_hash[31-n] & 0x0F];
	}

	cthash[64] = 0;
	chash[64] = 0;

	make_string(&tx_path, "txs");
	cat_ncstring_p(&tx_path, cthash, 2);
	cat_ncstring_p(&tx_path, cthash + 2, 2);
	ret = get_file(tx_path.str, &buffer, &size);
	free_string(&tx_path);
	if (ret <= 0)return 0;

	ret = 0;
	n = 0;
	while ((n+80)<=size)
	{
		if (!memcmp_c(&buffer[n], tx_hash, sizeof(hash_t)))
		{
			int nn= 0;
			while (nn<32)
			{
				blk_hash[nn] = buffer[n + 32 + nn];
				chash[nn * 2 + 0] = hex_chars[blk_hash[nn] >> 4];
				chash[nn * 2 + 1] = hex_chars[blk_hash[nn] & 0x0F];
				nn++;
			}
			chash[64]	= 0;
			ofset		= *((unsigned int *)(buffer+n+72));
			ret = 1;
			break;
		}
		n += 80;
	}
	free_c(buffer);
	if (!ret)return 0;
	ret = blk_load_tx_ofset(chash, ofset, tx);

	tree_manager_get_child_value_hash(tx,calc_crc32_c("txid"),th);

	if(memcmp_c(th,tx_hash,sizeof(hash_t)!=0))
	{
		ret=0;
		log_message("error chcking tx hash %txid% ",tx);
	}


	return ret;
}

__declspec(dllexport) int  load_tx_addresses(btc_addr_t addr, mem_zone_ref_ptr tx_hashes)
{
	btc_addr_t null_addr = { 0 };
	unsigned char *data;
	size_t len;
	struct string tx_file = { 0 };

	memset_c		(null_addr, '0', sizeof(btc_addr_t));

	make_string		(&tx_file, "adrs");
	cat_ncstring_p	(&tx_file, &addr[31], 2);

	if (get_file(tx_file.str, &data, &len) > 0)
	{
		size_t idx_sz, n = 0, idx = 0;
		uint64_t ftx, ttx, ntx = 0, aidx;
		unsigned char *first_tx;

		ttx = 0;
		while (n < len)
		{
			if (!memcmp_c(&data[n], null_addr, sizeof(btc_addr_t)))
				break;


			if (!memcmp_c(&data[n], addr, sizeof(btc_addr_t)))
			{
				ftx = ttx;
				ntx = *((uint64_t *)(data + n + sizeof(btc_addr_t)));
				aidx = idx;
			}

			ttx += *((uint64_t *)(data + n + sizeof(btc_addr_t)));
			n += sizeof(btc_addr_t) + sizeof(uint64_t);
			idx++;
		}

		if (ntx>0)
		{
			int nn;
			idx_sz = idx*(sizeof(btc_addr_t) + sizeof(uint64_t)) + sizeof(btc_addr_t);
			first_tx = data + idx_sz + ftx*sizeof(hash_t);
			nn = 0;
			while (nn < ntx)
			{
				mem_zone_ref new_hash = { (void *)0x00000000L };
				uint64_t  height,time;
				unsigned int tx_time;

				if (get_tx_blk_height(first_tx + nn*sizeof(hash_t), &height, &time, &tx_time))
				{
					if (tree_manager_add_child_node(tx_hashes, "tx", 0x0B001000, &new_hash))
					{
						tree_manager_write_node_hash(&new_hash, 0, first_tx + nn*sizeof(hash_t));
						release_zone_ref(&new_hash);
					}
				}
				nn++;
			}
		}
		free_c(data);
	}

	free_string(&tx_file);
	return 0;
}

int blk_del_app_root()
{
	struct string	app_root_path = { 0 };

	make_string(&app_root_path, "apps");
	cat_cstring_p(&app_root_path, "root_app");

	del_file(app_root_path.str);

	set_root_app((void *)0x00000000L);

	free_string(&app_root_path);

	return 1;
}

int del_utxo   (const char *txh,unsigned int oidx)
{
	char			dir[16];
	struct string	tx_path = { 0 } ;
	int				ret;

	get_utxo_path	(txh,oidx,&tx_path);
	ret=del_file	(tx_path.str);
	free_string		(&tx_path);

	strcpy_cs		(dir,32, "utxos");
	strcat_cs		(dir,32, "/");
	strncat_c		(dir, txh + 0, 2);
	strcat_cs		(dir,32, "/");
	strncat_c		(dir, txh + 2, 2);
	del_dir			(dir);


	return ret;
}


__declspec(dllexport) int  check_utxo  (const char *txh,unsigned int oidx)
{
	struct string	tx_path = { 0 } ;
	int				ret;
	
	get_utxo_path	(txh,oidx,&tx_path);

	ret=(stat_file	(tx_path.str)==0)? 1 : 0;

	free_string(&tx_path);

	return ret;
}

int load_utxo(const char *txh,unsigned int oidx,uint64_t *amount,btc_addr_t addr)
{
	struct	string tx_path={0};
	int		sret,ret;

	get_utxo_path	(txh,oidx,&tx_path);

	ret  = 0;
	sret = stat_file(tx_path.str);
	if (sret == 0)
	{
		unsigned char *buffer;
		size_t		  len;
		if (get_file(tx_path.str, &buffer, &len)>0)
		{
			if (len >= (sizeof(uint64_t) + sizeof(btc_addr_t)))
			{
				*amount		=	*((uint64_t *)(buffer));
				memcpy_c	(addr, buffer + sizeof(uint64_t),sizeof(btc_addr_t));
				ret=1;
			}
			free_c(buffer);
		}
	}
	free_string(&tx_path);
	return ret;
}


int store_tx_vout(const char *txh,mem_zone_ref_ptr txout_list,unsigned int oidx, btc_addr_t out_addr)
{
	struct string		script = { 0 }, tx_path = { 0 } ;
	mem_zone_ref		vout = {(void *)0x00000000L};

	uint64_t			amount;
	int					ret;

	if (!tree_manager_get_child_at(txout_list, oidx, &vout))
	{
		log_output("store vout bad utxo\n");
		return 0;
	}
	
	ret=tree_manager_get_child_value_i64	(&vout, calc_crc32_c("value"), &amount);
	if (!ret)
	{
		log_output("store vout no value\n");
		release_zone_ref(&vout);
		return 0;
	}
	ret=tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &script, 16);
	release_zone_ref(&vout);
	if (!ret)
	{
		log_output("store vout no script\n");
		return 0;
	}
	if ((amount == 0) && (script.len == 0))
	{ 
		free_string(&script); 
		return 1;
	}
	

	ret = get_out_script_address(&script, (void *)0x00000000L, out_addr);
	if(ret)
	{
		unsigned char		bbuffer[64];

		*((uint64_t *)(bbuffer)) = amount;
		memcpy_c	 (bbuffer + sizeof(uint64_t), out_addr, sizeof(btc_addr_t));

		get_utxo_path(txh,oidx,&tx_path);
		put_file	 (tx_path.str, bbuffer, sizeof(uint64_t) + sizeof(btc_addr_t));
		free_string	 (&tx_path);
	}
	else
	{
		log_output("store vout no addr\n");
	}
	
	
	free_string		(&script);

	return ret;
}

__declspec(dllexport) int  remove_tx_addresses(const btc_addr_t addr, const hash_t tx_hash)
{
	btc_addr_t		null_addr;
	struct string   tx_file = { 0 };
	size_t			len;
	unsigned char  *data;

	memset_c		(null_addr, '0', sizeof(btc_addr_t));

	
	make_string		(&tx_file, "adrs");
	cat_ncstring_p	(&tx_file, &addr[31], 2);

	if (get_file(tx_file.str, &data, &len)>0)
	{
		size_t		idx_sz, tx_list_ofs, ftidx;
		size_t		n = 0, idx = 0;
		uint64_t	ftx, ttx, cntx = 0, ntx = 0, aidx;
		unsigned char *first_tx;

		ttx = 0;
		while ((n + sizeof(btc_addr_t)) <= len)
		{
			
			if (!memcmp_c(&data[n], null_addr, sizeof(btc_addr_t)))
				break;

			cntx = *((uint64_t *)(data + n + sizeof(btc_addr_t)));

			
			if (!memcmp_c(&data[n], addr, sizeof(btc_addr_t)))
			{
				
				ftx = ttx;

				
				ntx = cntx;

				
				aidx = idx;
			}

			
			ttx += cntx;

			
			n += sizeof(btc_addr_t) + sizeof(uint64_t);
			idx++;
		}

		
		if (ntx > 0)
		{
			
			idx_sz		= idx*(sizeof(btc_addr_t) + sizeof(uint64_t));


			
			tx_list_ofs = idx_sz + sizeof(btc_addr_t);

			
			first_tx	= data + tx_list_ofs + ftx * sizeof(hash_t);

			
			n = 0;
			while (n < ntx)
			{
				if (!memcmp_c(first_tx + n*sizeof(hash_t), tx_hash, sizeof(hash_t)))
				{
					uint64_t	*addr_ntx_ptr;
					size_t		next_tx_pos;

					addr_ntx_ptr = (uint64_t	*)(data + aidx*(sizeof(btc_addr_t) + sizeof(uint64_t)) + sizeof(btc_addr_t));
					*addr_ntx_ptr = ntx - 1;

					
					ftidx = (ftx + n)*sizeof(hash_t);
					next_tx_pos = tx_list_ofs + ftidx + sizeof(hash_t);
					
					put_file("newfile", data, tx_list_ofs + ftidx);

					
					append_file("newfile", data + next_tx_pos, len - next_tx_pos);


					
					del_file(tx_file.str);
					move_file("newfile", tx_file.str);
					break;
				}
				n++;
			}
		}
		free_c(data);
	}
	free_string(&tx_file);
	return 1;
}


int rm_hash_from_file_obj(const char *file_name, hash_t hash)
{
	unsigned char *buffer;
	size_t			len;
	if (get_file(file_name, &buffer, &len)>0)
	{
		size_t  cur = 0;
		while (cur < len)
		{
			if (!memcmp_c(&buffer[cur], hash, sizeof(hash_t)))
			{
				len -= 32;
				if (len > 0)
				{
					if (len > cur)
						memmove_c(&buffer[cur], &buffer[cur + 32], len - cur);

					put_file(file_name, buffer, len);
				}
				else
					del_file(file_name);
				break;
			}
			cur += 32;
		}
		free_c(buffer);
	}
	return 1;
}




int rm_hash_from_index(const char *file_name, hash_t hash)
{
	unsigned char *buffer;
	size_t			len;
	if (get_file(file_name, &buffer, &len)>0)
	{
		size_t  cur = 0;
		while (cur < len)
		{
			if (!memcmp_c(&buffer[cur+4], hash, sizeof(hash_t)))
			{
				len -= 36;
				if (len > 0)
				{
					if (len>cur)
						memmove_c(&buffer[cur], &buffer[cur + 36], len - cur);

					put_file(file_name, buffer, len);
				}
				else
					del_file (file_name);
				break;
			}
			cur += 36;
		}
		free_c(buffer);
	}
	return 1;
}

void rm_hash_from_index_str(char *file_name, hash_t hash)
{

	unsigned char *buffer;
	size_t			len;
	if (get_file(file_name, &buffer, &len)>0)
	{
		size_t  cur = 0;
		while (cur < len)
		{
			unsigned char	sz	= *((unsigned char *)(buffer + cur));
			size_t entry_len	= (sz + 1 + sizeof(hash_t));

			if (!memcmp_c(&buffer[cur + sz + 1], hash, sizeof(hash_t)))
			{
				len -= entry_len;
				if (len > 0)
				{
					if (len>cur)
						memmove_c(&buffer[cur], &buffer[cur + entry_len], len - entry_len);

					put_file(file_name, buffer, len);
				}
				else
					del_file(file_name);

				break;
			}
			cur += entry_len;
		}
		free_c(buffer);
	}
	return ;
}

int rm_file_from_index(const char *file_name, hash_t hash)
{
	unsigned char *buffer;
	size_t			len;
	if (get_file(file_name, &buffer, &len)>0)
	{
		size_t  cur = 0;
		while (cur < len)
		{
			if (!memcmp_c(buffer, hash, sizeof(hash_t)))
			{
				len -= 64;
				if (len > 0)
				{
					if (len > cur)
						memmove_c(&buffer[cur], &buffer[cur + 64], len - cur);

					put_file(file_name, buffer, len);
				}
				else
					del_file(file_name);
				break;
			}
			cur += 64;
		}
		free_c(buffer);
	}
	return 1;
}

int rm_child_obj(const char *app_name, const char *tchash, const char *key, hash_t ch)
{
	struct string obj_path = { 0 };

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "objs");
	cat_cstring_p	(&obj_path, tchash);
	cat_cstring		(&obj_path, "_");
	cat_cstring		(&obj_path, key);
	rm_hash_from_file_obj(obj_path.str, ch);
	free_string(&obj_path);

	return 1;
}


int rm_obj(const char *app_name, unsigned int type_id, hash_t ohash)
{
	char objHash[65];
	char buff[16];
	mem_zone_ref		obj = { (void *)0x00000000L }, idxs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	idx = (void *)0x00000000L;
	struct string		obj_path = { 0 };
	unsigned int n;
		
	n = 0;
	while (n<32)
	{
		objHash[n * 2 + 0] = hex_chars[ohash[n] >> 4];
		objHash[n * 2 + 1] = hex_chars[ohash[n] & 0x0F];
		n++;
	}
	objHash[64] = 0;

	uitoa_s(type_id, buff, 16, 16);

	if (load_obj(app_name, objHash, "obj", 0, &obj, (void *)0x00000000L))
	{
		
		mem_zone_ref_ptr	key=(void *)0x00000000L;
		for (tree_manager_get_first_child(&obj, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &key))
		{
			if ((tree_mamanger_get_node_type(key) == 0x09000001) || (tree_mamanger_get_node_type(key) == 0x09000002))
			{
				const char *name = tree_mamanger_get_node_name(key);

				make_string		(&obj_path, "apps");
				cat_cstring_p	(&obj_path, app_name);
				cat_cstring_p	(&obj_path, "objs");
				cat_cstring_p	(&obj_path, objHash);
				cat_cstring		(&obj_path, "_");
				cat_cstring		(&obj_path, name);
				del_file		(obj_path.str);
				free_string		(&obj_path);
			}
		}
		release_zone_ref(&obj);
	}


	tree_manager_create_node("idxs", 0x09000001, &idxs);
	get_app_type_idxs(app_name, type_id, &idxs);


	for (tree_manager_get_first_child(&idxs, &my_list, &idx); ((idx != (void *)0x00000000) && (idx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &idx))
	{
		struct string idx_path = { 0 };
		const char *keyname;

		keyname = tree_mamanger_get_node_name(idx);

		make_string(&idx_path, "apps");
		cat_cstring_p(&idx_path, app_name);
		cat_cstring_p(&idx_path, "objs");
		cat_cstring_p(&idx_path, buff);
		cat_cstring(&idx_path, "_");
		cat_cstring(&idx_path, keyname);
		cat_cstring(&idx_path, ".idx");

		switch (tree_mamanger_get_node_type(idx))
		{
			case 0x00000002:
				rm_hash_from_index(idx_path.str, ohash);
			break;
			case 0x0B000100:
				rm_hash_from_index_str(idx_path.str, ohash);
			break;
		}
		free_string(&idx_path);
	}

	release_zone_ref(&idxs);
	

	make_string				(&obj_path, "apps");
	cat_cstring_p			(&obj_path, app_name);
	cat_cstring_p			(&obj_path, "objs");
	cat_cstring_p			(&obj_path, buff);
	rm_hash_from_file_obj	(obj_path.str, ohash);
	free_string				(&obj_path);

	make_string				(&obj_path, "apps");
	cat_cstring_p			(&obj_path, app_name);
	cat_cstring_p			(&obj_path, "objs");
	cat_cstring_p			(&obj_path, buff);
	cat_cstring				(&obj_path, "_time.idx");
	rm_hash_from_file_obj	(obj_path.str, ohash);
	free_string				(&obj_path);

	make_string				(&obj_path, "apps");
	cat_cstring_p			(&obj_path, app_name);
	cat_cstring_p			(&obj_path, "objs");
	cat_cstring_p			(&obj_path, objHash);
	del_file				(obj_path.str);
	free_string				(&obj_path);

	return 1;
}


int rm_type(const char *app_name, unsigned int type_id, const char *typeHash)
{
	struct string obj_path = { 0 };
	char buff[16];

	uitoa_s(type_id, buff, 16, 16);

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "types");
	cat_cstring_p	(&obj_path, typeHash);
	del_file		(obj_path.str);
	free_string		(&obj_path);

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "objs");
	cat_cstring_p	(&obj_path, buff);
	del_file		(obj_path.str);
	free_string		(&obj_path);

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "objs");
	cat_cstring_p	(&obj_path, buff);
	cat_cstring		(&obj_path, "_time.idx");
	del_file		(obj_path.str);
	free_string		(&obj_path);

	return 1;
}


int rm_app_file(const char *app_name, mem_zone_ref_ptr file)
{
	hash_t hash;
	char fileHash[65];
	struct string file_path = { 0 };
	unsigned int n;

	if (!tree_manager_get_child_value_hash(file, calc_crc32_c("dataHash"), hash))return 0;


	n = 0;
	while (n<32)
	{
		fileHash[n * 2 + 0] = hex_chars[hash[n] >> 4];
		fileHash[n * 2 + 1] = hex_chars[hash[n] & 0x0F];
		n++;
	}
	fileHash[64] = 0;

	make_string		(&file_path, "apps");
	cat_cstring_p	(&file_path, app_name);
	cat_cstring_p	(&file_path, "datas");
	cat_cstring_p	(&file_path, fileHash);
	del_file		(file_path.str);
	free_string		(&file_path);


	make_string		(&file_path, "apps");
	cat_cstring_p	(&file_path, app_name);
	cat_cstring_p	(&file_path, "datas");
	cat_cstring_p	(&file_path, "index");

	rm_file_from_index(file_path.str, hash);

	free_string	(&file_path);

	return 1;
}

int rm_app(const char *app_name)
{
	struct string app_path = { 0 };


	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	cat_cstring_p	(&app_path, "types");
	rm_dir			(app_path.str);
	free_string		(&app_path);

	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	cat_cstring_p	(&app_path, "objs");
	rm_dir			(app_path.str);
	free_string		(&app_path);

	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	cat_cstring_p	(&app_path, "layouts");
	rm_dir			(app_path.str);
	free_string		(&app_path);

	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	cat_cstring_p	(&app_path, "datas");
	rm_dir			(app_path.str);
	free_string		(&app_path);

	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	cat_cstring_p	(&app_path, "modz");
	rm_dir			(app_path.str);
	free_string		(&app_path);

	make_string		(&app_path, "apps");
	cat_cstring_p	(&app_path, app_name);
	rm_dir			(app_path.str);
	free_string		(&app_path);

	

	return 1;
}


__declspec(dllexport) int  remove_tx_index(hash_t tx_hash)
{
	char tchash[65];
	struct string tx_path = { 0 };
	unsigned char *buffer;
	size_t size;
	unsigned int ret, n;
	n = 0;
	while (n<32)
	{
		tchash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
		tchash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];
		n++;
	}
	tchash[64] = 0;


	
	make_string(&tx_path, "txs");
	cat_ncstring_p(&tx_path, tchash + 0, 2);
	cat_ncstring_p(&tx_path, tchash + 2, 2);

	if (get_file(tx_path.str, &buffer, &size) <= 0)
	{
		
		free_string(&tx_path);
		return 0;
	}

	ret = 0;
	n = 0;
	while ((n + 80) <= size)
	{
		if (!memcmp_c(&buffer[n], tx_hash, sizeof(hash_t)))
		{
			if ((n + 80)<size)
				truncate_file(tx_path.str, n, &buffer[n + 80], size - (n + 80));
			else if (n>0)
				truncate_file(tx_path.str, n, (void *)0x00000000L, 0);
			else
				del_file(tx_path.str);

			ret = 1;
			break;
		}
		n += 80;
	}
	if (size>0)
		free_c(buffer);

	free_string(&tx_path);

	return ret;
}



int cancel_tx_outputs(mem_zone_ref_ptr tx)
{
	char				tchash[65];
	mem_zone_ref	    txout_list = { (void *)0x00000000L };
	unsigned int		oidx,n_utxo;

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;

	if(!tree_manager_get_child_value_str(tx,calc_crc32_c("txid"),tchash,65,16))
	{
		hash_t h;
		compute_tx_hash						(tx,h);
		tree_manager_set_child_value_hash	(tx,"txid",h);
		tree_manager_get_child_value_str	(tx,calc_crc32_c("txid"),tchash,65,16);
	}

	n_utxo=tree_manager_get_node_num_children(&txout_list);
	for (oidx = 0; oidx<n_utxo; oidx++)
	{
		uint64_t amount;
		unsigned int app_item;
		get_tx_output_amount(tx, oidx, &amount);
		
		if (oidx == 0)
		{
			char			app_name[64];
			if (tree_manager_get_child_value_i32(tx, calc_crc32_c("is_app_item"), &app_item))
			{
				tree_manager_get_child_value_str(tx, calc_crc32_c("appName"), app_name, 64, 0);

				if (((amount & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000) && (app_item == 2))
				{
					hash_t			h;
					unsigned int	type_id;
					type_id = amount & 0xFFFFFFFF;

					tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), h);

					rm_obj(app_name, type_id, h);
					continue;
				}
				else if (app_item == 1)
				{
					char			typeName[32];
					mem_zone_ref	vout = { (void *)0x00000000L };
					struct string	oscript = { 0 };
					unsigned int	type_id,flags;

					get_tx_output(tx, 0, &vout);
					tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &oscript, 0);

					if (get_type_infos(&oscript, typeName, &type_id,&flags))
					{
						rm_type(app_name, type_id, tchash);
					}

					free_string(&oscript);
					release_zone_ref(&vout);
					continue;
				}
				else if (app_item == 3)
				{
					mem_zone_ref	vout = { (void *)0x00000000L }, file = { (void *)0x00000000L };
					struct string	oscript = { 0 };
					

					get_tx_output(tx, 0, &vout);
					tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &oscript, 0);

					tree_manager_create_node("file", 0x00000400, &file);
					
					if (get_script_file(&oscript, &file))
						rm_app_file(app_name, &file);

					release_zone_ref(&file);

					free_string(&oscript);
					release_zone_ref(&vout);
					continue;
				}
			}
			else if (tree_manager_get_child_value_str(tx, calc_crc32_c("objChild"), app_name, 64,0))
			{
				char			objHash[65];
				mem_zone_ref	vout = { (void *)0x00000000L };
				struct string	oscript = { 0 }, key = { 0 }, cHash = { 0 };
				size_t			offset = 0;
				int				ret;

				tree_manager_get_child_value_str(tx, calc_crc32_c("appChildOf"), objHash, 65, 0);
				

				get_tx_output(tx, 0, &vout);
				tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &oscript, 0);

				ret = get_script_data(&oscript, &offset, &key);
				if (ret)ret = get_script_data(&oscript, &offset, &cHash);
				ret = (cHash.len == 32) ? 1 : 0;
				if (ret)
				{
					rm_child_obj(app_name, objHash, key.str, cHash.str);
				}

				free_string(&key);
				free_string(&cHash);
				free_string(&oscript);

				continue;
			}
		}
		if (amount > 0)
		{
			del_utxo(tchash, oidx);
		}
	}
	release_zone_ref(&txout_list);
	return 1;
}

int cancel_tx_inputs(mem_zone_ref_ptr tx)
{
	mem_zone_ref	 txin_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr input = (void *)0x00000000L;
	int				 ret;


	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))return 0;

	
	for (tree_manager_get_first_child(&txin_list, &my_list, &input); ((input != (void *)0x00000000) && (input->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &input))
	{
		mem_zone_ref	 ptx = { (void *)0x00000000L };
		hash_t			 prev_hash, pblk_hash;
		unsigned int	 oidx;
		unsigned char	 app_item;

		tree_manager_get_child_value_hash(input, calc_crc32_c("txid"), prev_hash);
		tree_manager_get_child_value_i32 (input, calc_crc32_c("idx"), &oidx);


		if (tx_is_app_item(prev_hash, oidx, &ptx, &app_item))
		{
			release_zone_ref(&ptx);
			continue;
		}
		else if (!memcmp_c(prev_hash, app_root_hash, sizeof(hash_t)))
		{
			continue;
		}
		
		else if (load_tx(&ptx, pblk_hash, prev_hash))
		{
			char			 txh[65];
			btc_addr_t		 out_addr;
			mem_zone_ref	 txout_list = { (void *)0x00000000L };
			int			  	 n;

			
			n = 0;
			while (n<32)
			{
				txh[n * 2 + 0] = hex_chars[prev_hash[n] >> 4];
				txh[n * 2 + 1] = hex_chars[prev_hash[n] & 0x0F];
				n++;
			}
			txh[64] = 0;

			ret=tree_manager_find_child_node (&ptx, calc_crc32_c("txsout"), 0x0B080000, &txout_list);

			if(ret)ret=store_tx_vout		 (txh,&txout_list,oidx,out_addr);

			release_zone_ref(&txout_list);
			release_zone_ref(&ptx);
				
			






		}
	}
	release_zone_ref(&txin_list);
	return 1;
}



__declspec(dllexport) int  remove_tx(hash_t tx_hash)
{
	hash_t			blk_hash;
	mem_zone_ref	tx = { (void *)0x00000000L };

	
	if (load_tx(&tx, blk_hash, tx_hash))
	{
		if (is_app_root(&tx))
		{
			blk_del_app_root();
		}
		else
		{
			hash_t			hash;
			mem_zone_ref	vin = { (void *)0x00000000L }, ptx = { (void *)0x00000000L };
			unsigned char	app_item;
			unsigned int	oidx;

			if (get_tx_input(&tx, 0, &vin))
			{
				struct string app_name = { 0 };
				tree_manager_get_child_value_hash(&vin, calc_crc32_c("txid"), hash);
				tree_manager_get_child_value_i32(&vin, calc_crc32_c("idx"), &oidx);

				if ((has_root_app) && (!memcmp_c(hash, app_root_hash, sizeof(hash_t))))
				{
					struct string script = { 0 };

					tree_manager_get_child_value_istr	(&vin, calc_crc32_c("script"), &script,0);

					if(get_app_name	(&script, &app_name))
					{
						rm_app		(app_name.str);
						free_string	(&app_name);
					}

					tree_remove_child_by_member_value_hash(&apps, 0x0B008000, "txid", tx_hash);
					free_string	(&script);
				}
				else if (tx_is_app_item(hash, oidx, &ptx, &app_item))
				{
					const char *app_name = tree_mamanger_get_node_name(&ptx);

					tree_manager_set_child_value_str(&tx, "appName", app_name);
					tree_manager_set_child_value_i32(&tx, "is_app_item", app_item);
					release_zone_ref(&ptx);
				}
				else if (tx_is_app_child(hash, oidx, &app_name))
				{
					tree_manager_set_child_value_vstr(&tx, "objChild", &app_name);
					tree_manager_set_child_value_hash(&tx, "appChildOf", hash);
					free_string(&app_name);
				}
				release_zone_ref(&vin);
			}
			
			cancel_tx_outputs	(&tx);
			cancel_tx_inputs	(&tx);
		}

		release_zone_ref	(&tx);
	}
	
	remove_tx_index(tx_hash);

	return 1;
}



__declspec(dllexport) int  get_app_file(mem_zone_ref_ptr file_tx, struct string *app_name, mem_zone_ref_ptr file)
{
	hash_t			prev_hash;
	mem_zone_ref	input = { (void *)0x00000000L }, app_tx = { (void *)0x00000000L };
	unsigned int	oidx, ret = 0;
	unsigned char	app_item;

		
	if (get_tx_input(file_tx, 0, &input))
	{
		tree_manager_get_child_value_hash	(&input, calc_crc32_c("txid"), prev_hash);
		tree_manager_get_child_value_i32	(&input, calc_crc32_c("idx"), &oidx);

		if (tx_is_app_item(prev_hash, oidx, &app_tx, &app_item))
		{
			if (app_item == 3)
			{
				mem_zone_ref output = { (void *)0x00000000L };
				
				if (get_tx_output(file_tx, 0, &output))
				{
					struct string script = { 0 };

					tree_manager_get_child_value_istr(&output, calc_crc32_c("script"), &script,0);

					if (get_script_file(&script,file))
					{
						ret = 1;
						tree_manager_get_child_value_istr(&app_tx, calc_crc32_c("appName"), app_name,0);
					}
					free_string(&script);
					release_zone_ref(&output);
				}
			}
			release_zone_ref(&app_tx);
		}
		release_zone_ref(&input);
	}
	return ret;
}


__declspec(dllexport) int  has_app_file(struct string *app_name, hash_t fileHash)
{
	char chash[65];
	struct string app_path = { 0 };
	unsigned int n = 0;
	int ret;
	
	n = 0;
	while (n<32)
	{
		chash[n * 2 + 0] = hex_chars[fileHash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[fileHash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;

	make_string(&app_path, "apps");
	cat_cstring_p(&app_path, app_name->str);
	cat_cstring_p(&app_path, "datas");
	cat_cstring_p(&app_path, chash);

	ret = (stat_file(app_path.str) == 0) ? 1 : 0;

	free_string(&app_path);

	return ret;
}
__declspec(dllexport) int  get_appfile_tx(const char *app_name, hash_t fileHash, hash_t txHash)
{
	struct string app_path = { 0 };
	unsigned char *buffer;
	size_t len;
	int ret = 0;

	make_string(&app_path, "apps");
	cat_cstring_p(&app_path, app_name);
	cat_cstring_p(&app_path, "datas");
	cat_cstring_p(&app_path, "index");

	if (get_file(app_path.str, &buffer, &len)>0)
	{
		size_t cur = 0;

		while (cur < len)
		{
			if (!memcmp_c(buffer+cur, fileHash, sizeof(hash_t)))
			{
				memcpy_c(txHash, buffer + cur + 32, sizeof(hash_t));
				ret = 1;
				break;
			}
			cur += 64;
		}
		free_c(buffer);
	}
	free_string(&app_path);
	return ret;
}

__declspec(dllexport) int  get_app_files(struct string *app_name, size_t first, size_t num, mem_zone_ref_ptr files)
{
	struct string app_path = { 0 };
	unsigned char *buffer;
	size_t len,nh,total;
	int ret = 0;

	make_string(&app_path, "apps");
	cat_cstring_p(&app_path, app_name->str);
	cat_cstring_p(&app_path, "datas");
	cat_cstring_p(&app_path, "index");

	total = 0;
	nh = 0;

	if (get_file(app_path.str, &buffer, &len) > 0)
	{
		size_t cur	= first*64;

		total		= len / 64;

		while ((cur < len) && (nh  <num))
		{
			mem_zone_ref newh = { (void *)0x00000000L };

			if (tree_manager_add_child_node(files, "file", 0x0B001000, &newh))
			{
				tree_manager_write_node_hash(&newh, 0, buffer + cur + 32);
				release_zone_ref(&newh);
				nh ++;
			}
			cur += 64;
		}
		free_c(buffer);
	}
	free_string(&app_path);

	return total;
}

__declspec(dllexport) int  get_app_missing_files(struct string *app_name, mem_zone_ref_ptr pending, mem_zone_ref_ptr files)
{
	struct string app_path = { 0 };
	unsigned char *buffer;
	size_t len;
	int ret = 0;

	make_string(&app_path, "apps");
	cat_cstring_p(&app_path, app_name->str);
	cat_cstring_p(&app_path, "datas");
	cat_cstring_p(&app_path, "index");


	if (get_file(app_path.str, &buffer, &len) > 0)
	{
		size_t cur = 0;

		while (cur < len) 
		{
			char fHAsh[65];
			struct string filePath = { 0 };
			unsigned int n;

			if (!tree_find_child_node_by_member_name_hash(pending, 0x00000400, "hash", buffer + cur+32, (void *)0x00000000L))
			{
				n = 0;
				while (n < 32)
				{
					fHAsh[n * 2 + 0] = hex_chars[buffer[n + cur] >> 4];
					fHAsh[n * 2 + 1] = hex_chars[buffer[n + cur] & 0x0F];
					n++;
				}
				fHAsh[64] = 0;


				make_string(&filePath, "apps");
				cat_cstring_p(&filePath, app_name->str);
				cat_cstring_p(&filePath, "datas");
				cat_cstring_p(&filePath, fHAsh);

				if (stat_file(filePath.str) != 0)
				{
					mem_zone_ref newh = { (void *)0x00000000L };
					if (tree_manager_add_child_node(files, "file", 0x0A000080, &newh))
					{
						tree_manager_write_node_hash(&newh, 0, buffer + cur + 32);
						release_zone_ref(&newh);
					}
				}
				free_string(&filePath);
			}
			cur += 64;
		}
		free_c(buffer);
	}
	free_string(&app_path);

	return 1;
}

__declspec(dllexport) int  get_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs, size_t max)
{
	struct string	blk_path = { 0 };
	unsigned char	*ptxs;
	size_t			len, ntx;

	make_string(&blk_path, "blks");
	cat_ncstring_p(&blk_path, blk_hash + 0, 2);
	cat_ncstring_p(&blk_path, blk_hash + 2, 2);
	cat_cstring_p(&blk_path, blk_hash);
	cat_cstring(&blk_path, "_blk");


	if (get_file(blk_path.str, &ptxs, &len) >0)
	{
		ntx = 238;
		while (ntx < len)
		{
			mem_zone_ref tx = { (void *)0x00000000L };
			if (tree_manager_add_child_node(txs, "tx", 0x0B001000, &tx))
			{
				tree_manager_write_node_hash(&tx, 0, &ptxs[ntx]);
				release_zone_ref(&tx);
			}
			ntx += 32;
		}
		free_c(ptxs);
	}
	free_string(&blk_path);

	return 1;
}


__declspec(dllexport) int  load_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs)
{
	struct string	blk_path = { 0 };
	unsigned char	*ptxs;
	size_t			len;

	make_string(&blk_path, "blks");
	cat_ncstring_p(&blk_path, blk_hash + 0, 2);
	cat_ncstring_p(&blk_path, blk_hash + 2, 2);
	cat_cstring_p(&blk_path, blk_hash);
	cat_cstring(&blk_path, "_txs");
	if (get_file(blk_path.str, &ptxs, &len) >0)
	{
		size_t ofset = 0;

		while (ofset < len)
		{
			mem_zone_ref	tx = { (void *)0x00000000L };
			unsigned int	tx_size;

			tx_size = *((unsigned int *)(ptxs + ofset));

			if (tree_manager_add_child_node(txs, "tx", 0x0B008000, &tx))
			{
				hash_t		tmph, txh;

				init_node(&tx);
				read_node(&tx, ptxs + ofset + 4, tx_size);

				mbedtls_sha256(ptxs + ofset + 4, tx_size, tmph, 0);
				mbedtls_sha256(tmph, 32, txh, 0);

				tree_manager_set_child_value_i32(&tx, "size", tx_size);
				tree_manager_set_child_value_hash(&tx, "txid", txh);

				release_zone_ref(&tx);
			}
			ofset += (tx_size + 4);
		}
		free_c(ptxs);
	}
	free_string(&blk_path);

	return 1;
}



__declspec(dllexport) int  clear_tx_index()
{
	struct string	dir_list = { (void *)0x00000000L }, tx_path = { (void *)0x00000000L };
	size_t			cur, nfiles;

	nfiles = get_sub_dirs("txs", &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	txp = { (void *)0x00000000L };
			size_t			sz;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz = mem_sub(optr, ptr);

			make_string(&txp, "txs");
			cat_ncstring_p(&txp, optr, sz);
			rm_dir(txp.str);
			free_string(&txp);

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string(&dir_list);

	nfiles = get_sub_files("adrs", &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	txp = { (void *)0x00000000L };
			size_t			sz;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz = mem_sub(optr, ptr);

			make_string(&txp, "adrs");
			cat_ncstring_p(&txp, optr, sz);
			del_file(txp.str);
			free_string(&txp);

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string(&dir_list);
	return 1;
}

__declspec(dllexport) int  store_tx_inputs(mem_zone_ref_ptr tx)
{
	hash_t			 thash = { 0 }, nhash={ 0 };
	char			 tx_hash[65];
	struct string	 tx_path = { 0 };
	mem_zone_ref	 txin_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr input = (void *)0x00000000L;
	unsigned int	 vin;
	int				 n,ret;

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))
	{
		log_message("store_tx_inputs no txsin",(void *)0x00000000L);
		return 0;
	}
	

	compute_tx_hash(tx, nhash);

	if (!tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), thash))
		tree_manager_set_child_value_hash	(tx, "txid", nhash);

	if (memcmp_c(nhash, thash, sizeof(hash_t)))
	{
		mem_zone_ref log = { (void *)0x00000000L };

		tree_manager_create_node			("log", 0x0A000010, &log);
		tree_manager_set_child_value_hash	(&log, "h1", thash);
		tree_manager_set_child_value_hash	(&log, "h2", nhash);
		log_message							("store_tx_inputs bad tx hash %h1% != %h2%", &log);
		release_zone_ref					(&log);
		return 0;
	}

	n = 0;
	while (n<32)
	{
		tx_hash[n * 2 + 0] = hex_chars[thash[n] >> 4];
		tx_hash[n * 2 + 1] = hex_chars[thash[n] & 0x0F];
		n++;
	}
	tx_hash[64] = 0;

	
	for (vin = 0, tree_manager_get_first_child(&txin_list, &my_list, &input); ((input != (void *)0x00000000) && (input->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &input), vin++)
	{
		char			phash[65];
		hash_t			prev_hash = { 0 };
		uint64_t		amount;
		btc_addr_t		addr;
		int				n;
		unsigned int	oidx, objChild;

		if (!tree_manager_get_child_value_hash(input, calc_crc32_c("txid"), prev_hash))
		{
			log_output		("store_tx_inputs no txid\n");
			dec_zone_ref	(input);
			release_zone_ref(&my_list);
			release_zone_ref(&txin_list);
			return 0;
		}

		if (!tree_manager_get_child_value_i32(input, calc_crc32_c("idx"), &oidx))
		{
			log_output("store_tx_inputs no oidx\n");
			dec_zone_ref	(input);
			release_zone_ref(&my_list);
			release_zone_ref(&txin_list);
			return 0;
		}

		if (!memcmp_c(prev_hash, null_hash, sizeof(hash_t)))
		{
			btc_addr_t coinbase;
			memset_c(coinbase, '0', sizeof(btc_addr_t));
			tree_manager_set_child_value_btcaddr(input, "srcaddr", coinbase);
			continue;
		}
		else if (!memcmp_c(prev_hash, app_root_hash, sizeof(btc_addr_t)))
		{
			continue;
		}
		else if (tree_find_child_node_by_member_name_hash(&apps, 0x0B008000, "txid", prev_hash, (void *)0x00000000L))
		{
			continue;
		}
		else if (tree_manager_get_child_value_i32(input, calc_crc32_c("isObjChild"),&objChild))
		{
			continue;
		}
			
		n = 0;
		while (n<32)
		{
			phash[n * 2 + 0] = hex_chars[prev_hash[n] >> 4];
			phash[n * 2 + 1] = hex_chars[prev_hash[n] & 0x0F];
			n++;
		}
		phash[64] = 0;
	
		ret=load_utxo	(phash,oidx,&amount,addr);
		if(ret)
		{
			del_utxo								(phash, oidx);

			tree_manager_set_child_value_i64		(input, "amount" , amount);
			tree_manager_set_child_value_btcaddr	(input, "srcaddr", addr);
			store_tx_addresses						(addr, thash);
		}
	}
	release_zone_ref(&txin_list);
	return 1;
}


__declspec(dllexport) int  store_tx_addresses(btc_addr_t addr, hash_t tx_hash)
{
	btc_addr_t null_addr = { 0 };
	unsigned char *data;
	size_t len;
	struct string tx_file = { 0 };

	if (addr[0] == 0)return 1;

	memset_c		(null_addr, '0', sizeof(btc_addr_t));
	make_string		(&tx_file, "adrs");
	cat_ncstring_p	(&tx_file, &addr[31], 2);
	if (get_file(tx_file.str, &data, &len)>0)
	{
		size_t idx_sz, ftidx;
		size_t n = 0, idx = 0;
		uint64_t ftx, ttx, ntx = 0, aidx;
		unsigned char *first_tx;

		ttx = 0;
		while (n < len)
		{
			if (!memcmp_c(&data[n], null_addr, sizeof(btc_addr_t)))
				break;

			if (!memcmp_c(&data[n], addr, sizeof(btc_addr_t)))
			{
				ftx = ttx;
				ntx = *((uint64_t *)(data + n + sizeof(btc_addr_t)));
				aidx = idx;
			}
			ttx += *((uint64_t *)(data + n + sizeof(btc_addr_t)));
			n += sizeof(btc_addr_t) + sizeof(uint64_t);
			idx++;
		}
		idx_sz = idx*(sizeof(btc_addr_t) + sizeof(uint64_t));
		if (ntx > 0)
		{
			int fnd = 0;

			first_tx = data + idx_sz + sizeof(btc_addr_t) + ftx*sizeof(hash_t);
			n = 0;
			while (n < ntx)
			{
				if (!memcmp_c(first_tx + n*sizeof(hash_t), tx_hash, sizeof(hash_t)))
				{
					fnd = 1;
					break;
				}
				n++;
			}
			if (!fnd)
			{
				*((uint64_t *)(data + aidx*(sizeof(btc_addr_t) + sizeof(uint64_t)) + sizeof(btc_addr_t))) = ntx + 1;
				ftidx = (ftx + ntx)*sizeof(hash_t);
				put_file("newfile", data, idx_sz + sizeof(btc_addr_t) + ftidx);
				append_file("newfile", tx_hash, sizeof(hash_t));
				append_file("newfile", data + idx_sz + sizeof(btc_addr_t) + ftidx, len - (idx_sz + ftidx + sizeof(btc_addr_t)));
				del_file(tx_file.str);
				move_file("newfile", tx_file.str);
			}
		}
		else
		{
			uint64_t one = 1;

			put_file("newfile", data, idx_sz);
			append_file("newfile", addr, sizeof(btc_addr_t));
			append_file("newfile", &one, sizeof(uint64_t));
			append_file("newfile", data + idx_sz, len - (idx_sz));
			append_file("newfile", tx_hash, sizeof(hash_t));
			del_file(tx_file.str);
			move_file("newfile", tx_file.str);
		}

		free_c(data);
	}
	else
	{
		size_t s = sizeof(btc_addr_t) * 2 + sizeof(uint64_t);
		data = malloc_c(s);

		memcpy_c(data, addr, sizeof(btc_addr_t));
		*((uint64_t *)(data + sizeof(btc_addr_t))) = 1;
		memset_c(data + sizeof(btc_addr_t) + sizeof(uint64_t), '0', sizeof(btc_addr_t));
		put_file(tx_file.str, data, s);
		free_c(data);

		append_file(tx_file.str, tx_hash, sizeof(hash_t));
	}

	
	free_string(&tx_file);
	return 1;

}

__declspec(dllexport) int  store_tx_outputs(mem_zone_ref_ptr tx)
{
	hash_t				thash, nhash;
	char				tx_hash[65];
	mem_zone_ref		txout_list = { (void *)0x00000000L };
	unsigned int		oidx, n_utxo, app_item, childOf;
	int					n,ret=0;

	compute_tx_hash(tx, nhash);

	if (!tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), thash))
		tree_manager_set_child_value_hash(tx, "txid", nhash);

	if (memcmp_c(nhash, thash, sizeof(hash_t)))
	{
		mem_zone_ref log = { (void *)0x00000000L };

		tree_manager_dump_node_rec(tx,0,4);

		tree_manager_create_node("log", 0x0A000010, &log);
		tree_manager_set_child_value_hash(&log, "h1", thash);
		tree_manager_set_child_value_hash(&log, "h2", nhash);
		log_message("store_tx_outputs bad tx hash %h1% != %h2%", &log);
		release_zone_ref(&log);
		return 0;
	}

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))
	{
		log_output("store tx no utxos\n");
		return 0;
	}

	n = 0;
	while (n<32)
	{
		tx_hash[n * 2 + 0] = hex_chars[thash[n] >> 4];
		tx_hash[n * 2 + 1] = hex_chars[thash[n] & 0x0F];
		n++;
	}
	tx_hash[64] = 0;

	n_utxo=tree_manager_get_node_num_children(&txout_list);

	if (n_utxo <= 0)
	{
		log_output		("utxo count 0\n");
		release_zone_ref(&txout_list);
		return 0;
	}

	for (oidx = 0; oidx<n_utxo; oidx++)
	{
		btc_addr_t		out_addr = { 0 };
		
		if (tree_manager_find_child_node(tx, calc_crc32_c("AppName"), 0x00000001, (void *)0x00000000L))
		{
			struct string	script = { (void *)0x00000000L };
			mem_zone_ref	vout = { 0 };

			tree_manager_get_child_at				(&txout_list, oidx, &vout);
			if (tree_manager_get_child_value_istr	(&vout, calc_crc32_c("script"), &script, 16))
			{
				struct string my_val = { (void *)0x00000000L };
				ret = get_out_script_return_val(&script, &my_val);
				if (ret)
				{
					free_string(&my_val);
					continue;
				}
				free_string(&script);
			}
			release_zone_ref(&vout);
		}
		else if (tree_manager_get_child_value_i32(tx, calc_crc32_c("app_item"), &app_item))
		{
			uint64_t		amount;
			ret=get_tx_output_amount(tx, oidx, &amount);
			if (amount == 0)continue;
			if ((amount & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000)continue;
		}
		else if (tree_manager_get_child_value_i32(tx, calc_crc32_c("childOf"), &childOf))
		{
			uint64_t		amount;
			ret = get_tx_output_amount(tx, oidx, &amount);
			if (amount == 0)continue;
		}

		if (store_tx_vout(tx_hash, &txout_list, oidx, out_addr))
		{
			ret = store_tx_addresses(out_addr, thash);
			if (!ret)log_output("store_tx_addresses error\n");
		}
		else
			ret = 1;
		if (!ret)
			break;
	}
	release_zone_ref(&txout_list);
	
	
	
	return ret;
}



__declspec(dllexport) int  find_blk_hash(const hash_t tx_hash, hash_t blk_hash,uint64_t *height,unsigned int *ofset,unsigned int *tx_time)
{
	char				cthash[65];
	unsigned int		n = 32;
	struct string		tx_path = { 0 };
	unsigned char		*buffer;
	mem_size			size;
	int					ret;
	while (n--)
	{
		cthash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
		cthash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];
	}

	cthash[64] = 0;

	make_string		(&tx_path, "txs");
	cat_ncstring_p	(&tx_path, cthash, 2);
	cat_ncstring_p	(&tx_path, cthash + 2, 2);
	ret = get_file	(tx_path.str, &buffer, &size);
	free_string(&tx_path);
	if (ret <= 0)return 0;

	ret = 0;
	n = 0;
	while (n<size)
	{
		if (!memcmp_c(&buffer[n], tx_hash, sizeof(hash_t)))
		{
			memcpy_c(blk_hash, &buffer[n + 32], sizeof(hash_t));
			if(height!=(void *)0x00000000L)(*height)=*((uint64_t *)(buffer+n+64));
			if(ofset!=(void *)0x00000000L)(*ofset)=*((unsigned int *)(buffer+n+72));
			if(tx_time!=(void *)0x00000000L)(*tx_time)=*((unsigned int *)(buffer+n+76));
			ret = 1;
			break;
		}
		n += 80;
	}
	free_c(buffer);
	return ret;
}



__declspec(dllexport) int  get_block_time(const char *blkHash, ctime_t *time)
{
	struct string blk_path = { 0 };
	int ret;

	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, blkHash + 0, 2);
	cat_ncstring_p	(&blk_path, blkHash + 2, 2);
	cat_cstring_p	(&blk_path, blkHash);
	cat_cstring		(&blk_path, "_blk");

	ret = get_ftime	(blk_path.str, time);

	free_string		(&blk_path);

	return ret;
}

__declspec(dllexport) int  is_pow_block(const char *blk_hash)
{
	struct string	file_path = { 0 };
	unsigned char	*blk_data;
	size_t			len;
	int				ret=0;

	make_string		(&file_path, "blks");
	cat_ncstring_p	(&file_path, blk_hash + 0, 2);
	cat_ncstring_p	(&file_path, blk_hash + 2, 2);
	cat_cstring_p	(&file_path, blk_hash);
	cat_cstring		(&file_path, "_blk");

	if(get_file_len(file_path.str,205,&blk_data,&len)>0)
	{
		if(len>=205)
		{
			if((*((unsigned char *)(blk_data+172)))==1)
				ret=1;
		}
		free_c(blk_data);
	}
	else
		ret = 0;

	free_string(&file_path);

	return ret;
}


__declspec(dllexport) unsigned int  get_blk_ntxs(const char* blk_hash)
{
	struct string	blk_path = { 0 };
	size_t			ntx;
	int				size;

	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, blk_hash + 0, 2);
	cat_ncstring_p	(&blk_path, blk_hash + 2, 2);
	cat_cstring_p	(&blk_path, blk_hash);
	cat_cstring		(&blk_path, "_blk");

	size		=	file_size(blk_path.str);
	if(size>238)
		ntx = (size-238) / sizeof(hash_t);
	else
		ntx =  0;

	free_string(&blk_path);
	return ntx;
}


__declspec(dllexport) int  get_blk_height(const char *blk_hash, uint64_t *height)
{
	struct string	blk_path = { (void *)0x00000000L }, tx_path = { (void *)0x00000000L };
	unsigned char	*data;
	int				ret = 0;
	size_t			len;


	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, blk_hash + 0, 2);
	cat_ncstring_p	(&blk_path, blk_hash + 2, 2);
	cat_cstring_p	(&blk_path, blk_hash);
	cat_cstring		(&blk_path, "_blk");

	if(get_file_len(blk_path.str,88,&data,&len)>0)
	{
		if(len>=88)
		{
			*height	=*((uint64_t *)(data+80));
			ret		=1;
		}
		free_c(data);
	}
	else
		ret = 0;

	free_string(&blk_path);
	return ret;
}

__declspec(dllexport) int  get_tx_blk_height(const hash_t tx_hash, uint64_t *height, uint64_t *block_time, unsigned int *tx_time)
{
	char chash[65];
	hash_t blk_hash;
	struct string blk_path = { (void *)0x00000000L };
	ctime_t ctime;
	unsigned int n;

	if (!find_blk_hash(tx_hash, blk_hash,height, (void *)0x00000000L,tx_time))
		return 0;

	n = 32;
	while (n--)
	{
		chash[n * 2 + 0] = hex_chars[blk_hash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[blk_hash[n] & 0x0F];
	}
	chash[64] = 0;

	if (block_time != (void *)0x00000000L)
	{
		get_block_time(chash, &ctime);
		*block_time = ctime;
	}
	return 1;
}


__declspec(dllexport) int  get_block_size(const char *blk_hash, size_t *size)
{
	struct string	blk_path = { (void *)0x00000000L }, tx_path = { (void *)0x00000000L };
	unsigned char	*data;
	unsigned int	ntx,signlen;
	int				ret = 0;
	size_t			len;


	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, blk_hash + 0, 2);
	cat_ncstring_p	(&blk_path, blk_hash + 2, 2);
	cat_cstring_p	(&blk_path, blk_hash);
	cat_cstring		(&blk_path, "_blk");

	if(get_file_len(blk_path.str,96,&data,&len)>0)
	{
		if(len>=96)
		{
			ntx		=	*((unsigned int *)(data+88));
			signlen =	*((unsigned char *)(data+92));
			ret		=	1;
		}
		free_c			(data);
		free_string		(&blk_path);

		if(ret)
		{
			if(ntx<0xFD)
				*size = 1;
			else
				*size = 3;

			make_string		(&blk_path, "blks");
			cat_ncstring_p	(&blk_path, blk_hash + 0, 2);
			cat_ncstring_p	(&blk_path, blk_hash + 2, 2);
			cat_cstring_p	(&blk_path, blk_hash);
			cat_cstring		(&blk_path, "_txs");

			*size +=		(80 + (file_size(blk_path.str) - ntx*4));
		}
	}
	else
		ret = -1;

	free_string(&blk_path);
	return ret;
}

__declspec(dllexport) int  store_tx_blk_index(const hash_t tx_hash, const hash_t blk_hash,uint64_t height,size_t tx_ofset,unsigned int tx_time)
{
	char			tchash[65];
	unsigned char   buffer[80];
	struct string	tx_path = { 0 };
	int				n= 0;

	while (n<32)
	{
		tchash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
		tchash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];
		n++;
	}
	tchash[64] = 0;


	make_string		(&tx_path, "txs");
	cat_ncstring_p	(&tx_path, tchash + 0, 2);
	create_dir		(tx_path.str);
	cat_ncstring_p	(&tx_path, tchash + 2, 2);

	memcpy_c	(buffer		, tx_hash	, sizeof(hash_t));
	memcpy_c	(buffer+32	, blk_hash	, sizeof(hash_t));

	*((uint64_t *)(buffer+64))		=height;
	*((unsigned int *)(buffer+72))	=tx_ofset;
	*((unsigned int *)(buffer+76))	=tx_time;

	append_file (tx_path.str, buffer	, 80);
	free_string (&tx_path);

	return 1;
}

__declspec(dllexport) int  load_blk_hdr(mem_zone_ref_ptr hdr, const char *blk_hash)
{
	unsigned char		*hdr_data;
	size_t				hdr_data_len;
	struct string		blk_path = { (void *)0x00000000L };
	int    ret = 0;

	make_string(&blk_path, "blks");
	cat_ncstring_p(&blk_path, blk_hash, 2);
	cat_ncstring_p(&blk_path, blk_hash + 2, 2);
	cat_cstring_p(&blk_path, blk_hash);
	cat_cstring  (&blk_path, "_blk");

	

	if (get_file_len(blk_path.str, 205, &hdr_data, &hdr_data_len) > 0)
	{
		hash_t h1, h2,hash;
		int		n = 32;

		while (n--)
		{
			char    hex[3];
			hex[0] = blk_hash[n * 2 + 0];
			hex[1] = blk_hash[n * 2 + 1];
			hex[2] = 0;
			hash[n] = strtoul_c(hex, (void *)0x00000000L, 16);
		}

		mbedtls_sha256(hdr_data, 80, h1, 0);
		mbedtls_sha256(h1, 32, h2, 0);

		if (memcmp_c(h2, hash, sizeof(hash_t)))
		{
			log_output("bad block hash \n");
			free_string(&blk_path);
			free_c(hdr_data);

			return 0;
		}

		if ((hdr->zone != (void *)0x00000000L) || (tree_manager_create_node("blk", 0x0B000800, hdr)))
		{
			
			struct string sign;
			unsigned char vntx[16];
			unsigned char *hash_ptr;
			unsigned int ntx;
			uint64_t block_height;

			init_node(hdr);
			read_node(hdr, hdr_data, hdr_data_len);


			tree_manager_set_child_value_bhash(hdr, "blkHash", hash);


			
			block_height	=	*((uint64_t *)(hdr_data+80));
			
			tree_manager_set_child_value_i64(hdr,"height",block_height);

			ntx	=*((unsigned int *)(hdr_data+88));

			if (ntx < 0xFD)
				vntx[0] = ntx;
			else
			{
				vntx[0] = 0xFD;
				*((unsigned short *)(&vntx[1])) = (unsigned short)ntx;
			}
			tree_manager_set_child_value_vint(hdr, "ntx", vntx);

			
			sign.len=*((unsigned char *)(hdr_data+92));

			if(sign.len>0)
			{
				mem_zone_ref sig={(void *)0x00000000L};
				sign.str=(char *)(hdr_data+93);

				if (!tree_manager_find_child_node(hdr, calc_crc32_c("signature"), 0x0B800000, &sig))
					tree_manager_add_child_node(hdr, "signature", 0x0B800000, &sig);

				
				tree_manager_write_node_sig(&sig, 0, (unsigned char *)sign.str, sign.len);
				release_zone_ref(&sig);
				
			}

			hash_ptr=hdr_data+173;
			
			switch(hdr_data[172])
			{
				case 0:break;
				case 1:
					tree_manager_set_child_value_hash(hdr,"blk pow",hash_ptr);
				break;
				default:
					tree_manager_set_child_value_hash(hdr,"blk pos",hash_ptr);
				break;
			}
			ret = 1;
		}
		free_c(hdr_data);
	}
	free_string(&blk_path);

	return ret;
}

__declspec(dllexport) int  store_block_txs(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list)
{
	char				blk_hash[65];
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	mem_zone_ref		my_list = { (void *)0x00000000L };
	struct string		file_path={0};
	size_t				nc,n_tx;
	unsigned char		*blk_txs;

	tree_manager_get_child_value_str(header,calc_crc32_c("blkHash"),blk_hash,65,16);

	nc	   = tree_manager_get_node_num_children(tx_list);

	blk_txs = (unsigned char *)calloc_c(sizeof(hash_t), nc);

	for (n_tx=0,tree_manager_get_first_child(tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx), n_tx++)
	{
		tree_manager_get_child_value_hash	(tx,calc_crc32_c("txid"),&blk_txs[n_tx * 32]);
	}

	make_string		(&file_path, "blks");
	cat_ncstring_p	(&file_path, blk_hash + 0, 2);
	cat_ncstring_p	(&file_path, blk_hash + 2, 2);
	cat_cstring_p	(&file_path, blk_hash);
	cat_cstring		(&file_path, "_blk");
	append_file		(file_path.str,blk_txs,nc*32);
	free_string		(&file_path);
	free_c			(blk_txs);

	return 1;
}


__declspec(dllexport) int  blk_load_app_root()
{
	struct string	app_root_path={0};
	unsigned char	*root_app_tx;
	size_t			len;

	make_string		(&app_root_path,"apps");
	cat_cstring_p	(&app_root_path,"root_app");

	if(get_file(app_root_path.str,&root_app_tx,&len)>0)
	{
		mem_zone_ref			apptx={(void *)0x00000000L};

		if(tree_manager_create_node("rootapp",0x0B008000,&apptx))
		{
			tree_manager_add_child_node(&apptx, "txsin", 0x0B010000, (void *)0x00000000L);
			tree_manager_add_child_node(&apptx, "txsout", 0x0B080000, (void *)0x00000000L);
			read_node					(&apptx,root_app_tx,len);
			set_root_app				(&apptx);



			release_zone_ref			(&apptx);
		}
		free_c(root_app_tx);
	}
	free_string(&app_root_path);

	return 1;
}

int blk_load_app_types(mem_zone_ref_ptr app)
{
	struct string types_path = { 0 }, dir_list = { 0 };
	size_t  cur, nfiles;
	const char	*name;

	name = tree_mamanger_get_node_name(app);

	make_string		(&types_path, "apps");
	cat_cstring_p	(&types_path, name);
	cat_cstring_p	(&types_path, "types");


	nfiles = get_sub_files(types_path.str, &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	path = { 0 };
			size_t			sz, len;
			unsigned char	*buffer;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz  = mem_sub(optr, ptr);

			clone_string	(&path, &types_path);
			cat_ncstring_p	(&path, optr,sz);

			if (get_file(path.str, &buffer, &len)>0)
			{
				hash_t				txh;
				mem_zone_ref		new_type = { (void *)0x00000000L };

				tree_manager_create_node			("types", 0x0B008000, &new_type);

				init_node							(&new_type);
				read_node							(&new_type, buffer,len);
				compute_tx_hash						(&new_type, txh);
				tree_manager_set_child_value_hash	(&new_type, "txid", txh);
				add_app_tx_type						(app, &new_type);
				release_zone_ref					(&new_type);
				free_c								(buffer);
			}
			free_string(&path);

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string		(&dir_list);
	free_string		(&types_path);
	return 1;
}

int blk_load_app_scripts(mem_zone_ref_ptr app)
{
	struct string script_path = { 0 }, dir_list = { 0 }, appName = { 0 };
	size_t  cur, nfiles;
	

	tree_manager_get_child_value_istr(app, calc_crc32_c("appName"), &appName,0);

	make_string		(&script_path, "apps");
	cat_cstring_p	(&script_path, appName.str);
	cat_cstring_p	(&script_path, "modz");


	nfiles = get_sub_files(script_path.str, &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	path = { 0 };
			size_t			sz;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz  = mem_sub(optr, ptr);

			if (sz < 5){
				cur++;
				optr = ptr + 1;
				dir_list_len -= sz;
				continue;
			}

			if (!strncmp_c(&optr[sz - 5], ".site", 5))
			{
				mem_zone_ref script_var = { (void *)0x00000000L };
				char		 script_name[32];

				strncpy_cs(script_name, 32, optr, sz);

				clone_string	(&path, &script_path);
				cat_ncstring_p	(&path, optr, sz);
				if (load_script(path.str, script_name, &script_var, 1))
				{
					ctime_t ftime;
					get_ftime						(path.str, &ftime);
					tree_manager_write_node_dword	(&script_var, 0, ftime);
					add_app_script					(app, &script_var);
				}
				free_string		(&path);
				release_zone_ref(&script_var);
			}
			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string(&dir_list);
	free_string(&script_path);
	free_string(&appName);
	return 1;
}

__declspec(dllexport) int  blk_load_apps(mem_zone_ref_ptr apps)
{
	struct string dir_list = { 0 };
	size_t cur, nfiles;

	nfiles = get_sub_dirs("apps", &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	path = { 0 };
			size_t			sz, len;
			unsigned char	*buffer;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz = mem_sub(optr, ptr);

			make_string(&path, "apps");
			cat_ncstring_p(&path, optr, sz);
			cat_cstring_p(&path, "app");

			if (get_file(path.str, &buffer, &len)>0)
			{
				char app_name[128];
				mem_zone_ref new_app = { (void *)0x00000000L };
				strncpy_c(app_name, optr, sz);
				if (tree_manager_create_node(app_name, 0x0B008000, &new_app))
				{
					hash_t txh;
					mem_zone_ref txout_list = { (void *)0x00000000L };

					init_node			(&new_app);
					read_node			(&new_app, buffer,len);
					compute_tx_hash		(&new_app, txh);
					tree_manager_set_child_value_hash(&new_app, "txid", txh);

					add_app_tx			(&new_app, app_name);
					blk_load_app_types	(&new_app);
					blk_load_app_scripts(&new_app);
					release_zone_ref	(&new_app);
				}
				free_c(buffer);
			}
			free_string(&path);

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string(&dir_list);

	return 1;
}



int blk_store_app_root(mem_zone_ref_ptr tx)
{
	struct string	app_root_path={0};
	unsigned char	*root_app_tx;
	size_t			len;

	make_string		(&app_root_path,"apps");
	create_dir		(app_root_path.str);
	cat_cstring_p	(&app_root_path,"root_app");

	len			=	get_node_size(tx);
	root_app_tx =	(unsigned char	*)malloc_c(len);

	write_node		(tx,root_app_tx);
	put_file		(app_root_path.str,root_app_tx,len);

	free_string		(&app_root_path);

	return 1;
}

__declspec(dllexport) int  get_app_obj_hashes(const char *app_name,mem_zone_ref_ptr hash_list)
{
	struct string obj_path = { (void *)0x00000000L }, dir_list = { (void *)0x00000000L };
	size_t nfiles, cur;

	tree_remove_children(hash_list);

	make_string  (&obj_path, "apps");
	cat_cstring_p(&obj_path, app_name);
	cat_cstring_p(&obj_path, "objs");

	nfiles = get_sub_files(obj_path.str, &dir_list);
	if (nfiles > 0)
	{
		const char		*ptr, *optr;
		unsigned int	dir_list_len;

		dir_list_len = dir_list.len;
		optr = dir_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	txp = { (void *)0x00000000L };
			size_t			sz;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz = mem_sub(optr, ptr);

			if (sz == 64)
			{
				mem_zone_ref	hashn = { (void *)0x00000000L };
			
				if(tree_manager_add_child_node		(hash_list,"hash", 0x0B001000, &hashn))
				{
					hash_t			hash;
					unsigned int	n = 0;
					while (n<32)
					{
						char    hex[3];
						hex[0] = optr[n * 2 + 0];
						hex[1] = optr[n * 2 + 1];
						hex[2] = 0;
						hash[n] = strtoul_c(hex, (void *)0x00000000L, 16);
						n++;
					}
					tree_manager_write_node_hash(&hashn, 0, hash);
					release_zone_ref(&hashn);
				}
			}

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}

	free_string(&obj_path);
	free_string(&dir_list);
	return 1;
}
__declspec(dllexport) int  get_app_type_nobjs(const char *app_name, unsigned int type_id)
{
	char			typeStr[32];
	struct string	obj_path = { (void *)0x00000000L };
	size_t			size;
	uitoa_s(type_id, typeStr, 32, 16);

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "objs");
	cat_cstring_p	(&obj_path, typeStr);

	size = file_size(obj_path.str)/32;

	free_string		(&obj_path);

	return size;
}

__declspec(dllexport) int  get_app_type_obj_hashes(const char *app_name, unsigned int type_id,size_t first, size_t max, mem_zone_ref_ptr hash_list)
{
	char			typeStr[32];
	struct string	obj_path = { (void *)0x00000000L };
	unsigned char	*buffer;
	size_t			cur,len,nHashes;
	int				ret;

	uitoa_s(type_id, typeStr, 32, 16);

	tree_remove_children(hash_list);

	make_string			(&obj_path, "apps");
	cat_cstring_p		(&obj_path, app_name);
	cat_cstring_p		(&obj_path, "objs");
	cat_cstring_p		(&obj_path, typeStr);

	ret = (get_file(obj_path.str, &buffer, &len) > 0) ? 1 : 0;

	if (ret)
	{
		cur =  first * 32;
		nHashes = 0;

		while ((cur < len) && (nHashes<max))
		{
			mem_zone_ref	hashn = { (void *)0x00000000L };

			if (tree_manager_add_child_node(hash_list, "hash", 0x0B001000, &hashn))
			{
				tree_manager_write_node_hash(&hashn, 0, &buffer[cur]);
				release_zone_ref			(&hashn);
				nHashes++;
			}
			cur += 32;
		}
		free_c(buffer);
	}
	free_string(&obj_path);

	return ret;
}

__declspec(dllexport) int  get_app_type_last_objs_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list)
{
	char			typeStr[32];
	struct string	obj_path = { (void *)0x00000000L };
	unsigned char	*buffer;
	size_t			cur, len, nHashes;
	int				ret;

	uitoa_s(type_id, typeStr, 32, 16);

	tree_remove_children(hash_list);

	make_string(&obj_path, "apps");
	cat_cstring_p(&obj_path, app_name);
	cat_cstring_p(&obj_path, "objs");
	cat_cstring_p(&obj_path, typeStr);
	cat_cstring  (&obj_path, "_time.idx");

	ret = (get_file(obj_path.str, &buffer, &len) > 0) ? 1 : 0;

	if (ret)
	{
		cur = first * 36;
		nHashes = 0;

		while ((cur < len) && (nHashes<max))
		{
			mem_zone_ref	hashn = { (void *)0x00000000L };

			if (tree_manager_add_child_node(hash_list, "hash", 0x0B001000, &hashn))
			{
				tree_manager_write_node_hash(&hashn, 0, &buffer[cur+4]);
				release_zone_ref(&hashn);
				nHashes++;
			}
			cur += 36;
		}
		free_c(buffer);
	}
	free_string(&obj_path);

	return ret;
}

__declspec(dllexport) int  find_app_type_obj(const char *app_name, unsigned int type_id, const char *objHash, mem_zone_ref_ptr hash_list)
{
	char			typeStr[32];
	struct string	obj_path = { (void *)0x00000000L };
	unsigned char	*buffer;
	size_t			cur, len;
	size_t			ilen;
	int				ret;

	uitoa_s(type_id, typeStr, 32, 16);

	make_string(&obj_path, "apps");
	cat_cstring_p(&obj_path, app_name);
	cat_cstring_p(&obj_path, "objs");
	cat_cstring_p(&obj_path, typeStr);

	tree_remove_children(hash_list);

	ret  = (get_file(obj_path.str, &buffer, &len) > 0) ? 1 : 0;
	ilen = strlen_c(objHash);

	if (ret)
	{
		cur	= 0;
		ret = 0;
		while (cur < len) 
		{
			char			chash[65];
			unsigned int	n = 0;
			
			while (n<32)
			{
				chash[n * 2 + 0] = hex_chars[objHash[n] >> 4];
				chash[n * 2 + 1] = hex_chars[objHash[n] & 0x0F];
				n++;
			}
			chash[64] = 0;

			if (!strncmp_c(chash, objHash, ilen))
			{
				mem_zone_ref	hashn = { (void *)0x00000000L };

				ret = 1;

				if (hash_list != (void *)0x00000000L)
				{
					if (tree_manager_add_child_node(hash_list, "hash", 0x0B001000, &hashn))
					{
						tree_manager_write_node_hash(&hashn, 0, &buffer[cur]);
						release_zone_ref(&hashn);
					}
				}
				else
					break;
			}
			cur += 32;
		}
		free_c(buffer);
	}
	free_string(&obj_path);

	return ret;
}

__declspec(dllexport) int  load_obj_childs(const char *app_name, const char *objHash, const char *KeyName, size_t first, size_t max, unsigned int opts,mem_zone_ref_ptr objs)
{

	mem_zone_ref	app = { (void *)0x00000000L };
	struct string	obj_path = { 0 };
	unsigned char	*buffer;
	size_t			len;
	int				ret = 0;

	if (!tree_manager_find_child_node(&apps, calc_crc32_c(app_name), 0x0B008000, &app))return 0;


	make_string(&obj_path, "apps");
	cat_cstring_p(&obj_path, app_name);
	cat_cstring_p(&obj_path, "objs");
	cat_cstring_p(&obj_path, objHash);
	cat_cstring(&obj_path, "_");
	cat_cstring(&obj_path, KeyName);

	if (get_file(obj_path.str, &buffer, &len) > 0)
	{
		size_t cur = first*32;
		size_t nums = 0;

		while ((cur < len) && (nums<max))
		{
			if (opts & 1)
			{
				char oh[65];
				btc_addr_t addr;
				mem_zone_ref newobj = { (void *)0x00000000L };
				unsigned int n;


				n = 0;
				while (n < 32)
				{
					oh[n * 2 + 0] = hex_chars[buffer[cur + n] >> 4];
					oh[n * 2 + 1] = hex_chars[buffer[cur + n] & 0x0F];
					n++;
				}
				oh[64] = 0;

				load_obj							(app_name, oh, "obj", 0, &newobj, addr);
				tree_manager_set_child_value_btcaddr(&newobj, "objAddr", addr);


				tree_manager_node_add_child (objs, &newobj);
				release_zone_ref			(&newobj);
			}
			else
			{
				mem_zone_ref hashn = { (void *)0x00000000L };
				if (tree_manager_add_child_node(objs, "hash", 0x0B001000, &hashn))
				{
					tree_manager_write_node_hash(&hashn, 0, &buffer[cur]);
					release_zone_ref(&hashn);
					nums++;
				}
			}
			cur += 32;
		}
		free_c(buffer);
	}
	free_string(&obj_path);

	return 1;
}

__declspec(dllexport) int  load_obj_type(const char *app_name, const char *objHash, unsigned int *type_id, btc_addr_t objAddr)
{
	mem_zone_ref	app = { (void *)0x00000000L };
	struct string	obj_path = { 0 };
	unsigned char	*tx_data;
	size_t			tx_len;
	int				ret = 0;

	if (!tree_manager_find_child_node(&apps, calc_crc32_c(app_name), 0x0B008000, &app))return 0;

	make_string(&obj_path, "apps");
	cat_cstring_p(&obj_path, app_name);
	cat_cstring_p(&obj_path, "objs");
	cat_cstring_p(&obj_path, objHash);

	if (get_file(obj_path.str, &tx_data, &tx_len) > 0)
	{
		mem_zone_ref obj_tx = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
		tree_manager_create_node("tx", 0x0B008000, &obj_tx);
		init_node(&obj_tx);
		read_node(&obj_tx, tx_data,tx_len);
		free_c(tx_data);

		if (get_tx_output(&obj_tx, 0, &vout))
		{
			uint64_t	value;
			tree_manager_get_child_value_i64(&vout, calc_crc32_c("value"), &value);
			if (objAddr != (void *)0x00000000L)
			{
				struct string		objStr = { (void *)0x00000000L };
				tree_manager_get_child_value_istr	(&vout, calc_crc32_c("script"), &objStr, 0);
				get_out_script_address				(&objStr, (void *)0x00000000L, objAddr);
				free_string							(&objStr);
			}
				

			if ((value & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000)
			{
				*type_id = value & 0xFFFFFFFF;
				ret = 1;
			}
			release_zone_ref(&vout);
		}

		release_zone_ref(&obj_tx);
	}


	free_string(&obj_path);
	release_zone_ref(&app);

	return ret;
}

__declspec(dllexport) int  load_obj(const char *app_name, const char *objHash, const char *objName, unsigned int opts, mem_zone_ref_ptr obj,btc_addr_t objAddr)
{
	mem_zone_ref	app = { (void *)0x00000000L };
	struct string	obj_path = { 0 };
	unsigned char	*tx_data;
	size_t			tx_len;
	int				ret=0;



	if (!tree_manager_find_child_node(&apps, calc_crc32_c(app_name), 0x0B008000, &app))return 0;

	make_string		(&obj_path, "apps");
	cat_cstring_p	(&obj_path, app_name);
	cat_cstring_p	(&obj_path, "objs");
	cat_cstring_p	(&obj_path, objHash);

	if (get_file(obj_path.str, &tx_data, &tx_len)>0)
	{
		hash_t oh;
		mem_zone_ref obj_tx = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
		unsigned int  time;
		tree_manager_create_node("tx", 0x0B008000, &obj_tx);
		init_node				(&obj_tx);
		read_node				(&obj_tx,tx_data,tx_len);
		free_c					(tx_data);

		if (get_tx_output(&obj_tx, 0, &vout))
		{
			uint64_t	value;
			unsigned int type_id;

			tree_manager_get_child_value_i32(&obj_tx, calc_crc32_c("time")	, &time);
			tree_manager_get_child_value_i64(&vout	, calc_crc32_c("value"), &value);

			if ((value & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000)
			{
				mem_zone_ref types = { (void *)0x00000000L }, type = { (void *)0x00000000L };
				
				type_id			= value & 0xFFFFFFFF;
				
				get_app_types	(&app, &types);
				
				if (tree_find_child_node_by_id_name(&types, 0x0B008000, "typeId", type_id, &type))
				{
					struct string		objStr = { (void *)0x00000000L }, objData = { 0 };
					mem_zone_ref		type_outs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
					mem_zone_ref_ptr	key = (void *)0x00000000L;

					tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &objStr, 0);

					ret = obj_new(&type, objName, &objStr, obj);
					release_zone_ref(&type);

					if (objAddr != (void *)0x00000000L)
						get_out_script_address(&objStr, (void *)0x00000000L, objAddr);

					free_string(&objStr);


					if (ret)
					{
						if (opts & 1)
						{
							for (tree_manager_get_first_child(obj, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &key))
							{
								unsigned int type;
								type = tree_mamanger_get_node_type(key);

								if ((type >> 24) == 0x1E)
								{
									char			chash[256];
									mem_zone_ref	subObj = { (void *)0x00000000L };
									unsigned char	*hdata;
									unsigned int	n;
									hdata = tree_mamanger_get_node_data_ptr(key, 0);

									n = 0;
									while (n < 32)
									{
										chash[n * 2 + 0] = hex_chars[hdata[n] >> 4];
										chash[n * 2 + 1] = hex_chars[hdata[n] & 0x0F];
										n++;
									}
									chash[64] = 0;

									ret = load_obj(app_name, chash, "item", opts, &subObj, (void *)0x00000000L);
									tree_manager_copy_children_ref(key, &subObj);
									release_zone_ref(&subObj);

								}
							}
						}
						if (opts & 2)
						{
							for (tree_manager_get_first_child(obj, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &key))
							{
								unsigned int type;
								type = tree_mamanger_get_node_type(key);

								if ((type == 0x09000001) || (type == 0x09000002))
								{
									const char *keyname = tree_mamanger_get_node_name(key);

									load_obj_childs(app_name, objHash, keyname, 0, 10, 1, key);

									




								}
							}
						}
					}
				}
				release_zone_ref(&types);
			}
			release_zone_ref(&vout);
			
			compute_tx_hash					 (&obj_tx, oh);
			tree_manager_set_child_value_hash(obj, "objHash", oh);
			tree_manager_set_child_value_i32 (obj, "time", time);
		}
		
		release_zone_ref(&obj_tx);
	}

	free_string(&obj_path);
	release_zone_ref(&app);

	return ret;

}

void add_index(const char *app_name, const char *typeStr, const char *keyname, unsigned int val, const hash_t hash)
{
	char			buffer[36];
	struct string	idx_path = { 0 };
	unsigned char	*idx_buff;
	size_t			idx_len, cur;

	memcpy_c(buffer, &val, 4);
	memcpy_c(&buffer[4], hash, 32);


	make_string	 (&idx_path, "apps");
	cat_cstring_p(&idx_path, app_name);
	cat_cstring_p(&idx_path, "objs");
	cat_cstring_p(&idx_path, typeStr);
	cat_cstring  (&idx_path, "_");
	cat_cstring  (&idx_path, keyname);
	cat_cstring  (&idx_path, ".idx");
	
	if (get_file(idx_path.str, &idx_buff, &idx_len) > 0)
	{

		cur = 0;
		while (cur < idx_len)
		{
			if (val >  *((unsigned int *)(idx_buff + cur)))break;
			cur += 36;
		}

		truncate_file(idx_path.str, cur, buffer, 36);


		if (idx_len > cur)
			append_file(idx_path.str, &idx_buff[cur], idx_len - cur);

		free_c(idx_buff);
	}
	else
		put_file(idx_path.str, buffer, 36);

	
	free_string	(&idx_path);
}

void add_index_str(const char *app_name, const char *typeStr, const char *keyname, const struct string *val, const hash_t hash)
{
	char			newval[512];
	struct string	idx_path = { 0 };
	unsigned char	*idx_buff;
	size_t			idx_len, cur;

	newval[0] = val->len;
	strcpy_cs	(&newval[1], 511, val->str);
	memcpy_c	(&newval[1 + val->len], hash, sizeof(hash_t));


	make_string(&idx_path, "apps");
	cat_cstring_p(&idx_path, app_name);
	cat_cstring_p(&idx_path, "objs");
	cat_cstring_p(&idx_path, typeStr);
	cat_cstring(&idx_path, "_");
	cat_cstring(&idx_path, keyname);
	cat_cstring(&idx_path, ".idx");

	if (get_file(idx_path.str, &idx_buff, &idx_len) > 0)
	{
		cur = 0;
		while (cur < idx_len)
		{
			char sval[256];
			unsigned char	sz = *((unsigned char *)(idx_buff + cur));

			strncpy_cs(sval, 256, (idx_buff + cur + 1),sz);

			if (strcmp_c(val->str, sval)<0)
				break;

			cur += sizeof(hash_t) + sz + 1;
		}

		truncate_file(idx_path.str, cur, newval, sizeof(hash_t) + val->len + 1);


		if (idx_len > cur)
			append_file(idx_path.str, &idx_buff[cur], idx_len - cur);

		free_c(idx_buff);
	}
	else
		put_file(idx_path.str, newval, sizeof(hash_t) + val->len + 1);


	free_string(&idx_path);
}

int find_index_str(const char *app_name, const char *typeStr, const char *keyname, const struct string *val, hash_t hash)
{
	struct string	idx_path = { 0 };
	unsigned char	*idx_buff;
	size_t			idx_len, cur;
	int ret=0;

	make_string(&idx_path, "apps");
	cat_cstring_p(&idx_path, app_name);
	cat_cstring_p(&idx_path, "objs");
	cat_cstring_p(&idx_path, typeStr);
	cat_cstring(&idx_path, "_");
	cat_cstring(&idx_path, keyname);
	cat_cstring(&idx_path, ".idx");

	if (get_file(idx_path.str, &idx_buff, &idx_len) > 0)
	{
		cur = 0;
		while ((cur+1) < idx_len)
		{
			char			sval[256];
			int				stret;
			unsigned char	sz = *((unsigned char *)(idx_buff + cur));
			
			if ((cur + 1+ sz+32)>idx_len)break;

			strncpy_cs(sval,256, (idx_buff + cur + 1), sz);

			stret = strcmp_c(val->str, sval);

			if (stret == 0){
				memcpy_c(hash, (idx_buff + cur + 1 + sz), sizeof(hash_t));
				ret = 1; 
				break;
			}

			cur += sizeof(hash_t) + sz + 1;
		}
		free_c(idx_buff);
	}

	free_string(&idx_path);


	return ret;
}


__declspec(dllexport) int  store_block(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list)
{
	unsigned char		blkbuffer[512];
	char				chash[65];
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	mem_zone_ref		my_list = { (void *)0x00000000L };
	size_t				length, tx_ofset;
	uint64_t			height;
	hash_t				blk_hash;
	unsigned char		*hash_ptr;
	int					ret;
	struct string		signature = { 0 }, blk_path = { 0 }, blk_data_path = { 0 };
	unsigned int		n, n_tx, nc, block_time;
	

	if (!tree_manager_get_child_value_hash(header, calc_crc32_c("blkHash"), blk_hash))return 0;

	n = 0;
	while (n<32)
	{
		chash[n * 2 + 0] = hex_chars[blk_hash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[blk_hash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;

	make_string(&blk_path, "blks");
	cat_ncstring_p(&blk_path, chash + 0, 2);
	create_dir(blk_path.str);

	cat_ncstring_p(&blk_path, chash + 2, 2);
	create_dir(blk_path.str);

	cat_cstring_p(&blk_path, chash);
	
	

	nc	   = tree_manager_get_node_num_children(tx_list);
	height = get_last_block_height() + 1;
	length = 80+8+4+33+80+33; 


	write_node(header, (unsigned char *)blkbuffer);

	*((uint64_t *)(blkbuffer+80))=height;
	*((unsigned int *)(blkbuffer+88))=nc;

	if (tree_manager_get_child_value_istr(header, calc_crc32_c("signature"), &signature, 0))
	{
		*((unsigned char *)(blkbuffer+92))=signature.len;
		memcpy_c(blkbuffer+93,signature.str,signature.len);

		free_string(&signature);
	}
	
	hash_ptr=blkbuffer+173;

	if (tree_manager_get_child_value_hash(header, calc_crc32_c("blk pow"), hash_ptr))
	{
		*((unsigned char *)(blkbuffer+172))=1;
	}
	else{
		memset_c(blkbuffer+172,0,33);
	}

	memset_c(blkbuffer+205,0,33);

	clone_string	(&blk_data_path, &blk_path);
	cat_cstring		(&blk_data_path, "_blk");
	ret=put_file	(blk_data_path.str, blkbuffer, length);

	if (ret!=length)
	{
		log_output("bad write block\n");
		free_string(&blk_path);
		return 0;
	}

	if (stat_file(blk_data_path.str) != 0)
	{
		log_output("bad write block\n");
		free_string(&blk_path);
		return 0;
	}

	if (tree_manager_get_child_value_i32(header, calc_crc32_c("time"), &block_time))
		set_ftime(blk_data_path.str, block_time);

	free_string(&blk_data_path);

	if (nc <= 0)
	{
		free_string(&blk_path);
		return 0;
	}
	
	clone_string(&blk_data_path, &blk_path);
	cat_cstring (&blk_data_path, "_txs");

	tx_ofset = 0;

	for (n_tx = 0, tree_manager_get_first_child(tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx), n_tx++)
	{
		hash_t				tx_hash, pObjHash;
		struct string		app_name = { 0 };
		unsigned int		tx_time, app_item;
		unsigned char		*buffer;

		length = get_node_size(tx);
		buffer = (unsigned char *)malloc_c(length);
		write_node(tx, (unsigned char *)buffer);

		if (!tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), tx_hash))
		{
			hash_t tmp_hash;

			mbedtls_sha256((unsigned char *)buffer, length, tmp_hash, 0);
			mbedtls_sha256(tmp_hash, 32, tx_hash, 0);
			tree_manager_set_child_value_hash(tx, "txid", tx_hash);
		}

		if (!tree_manager_get_child_value_i32(tx, calc_crc32_c("time"), &tx_time))
			tx_time = block_time;
		
		if (tree_manager_get_child_value_istr(tx, calc_crc32_c("AppName"),&app_name,0))
		{
			mem_zone_ref app_tx = { (void *)0x00000000L };
			struct string app_path = { 0 };
			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			create_dir(app_path.str);

			cat_cstring_p(&app_path, "app");
			put_file(app_path.str, buffer, length);

			
			free_string(&app_path);

			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			cat_cstring_p(&app_path, "types");
			create_dir(app_path.str);
			free_string(&app_path);

			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			cat_cstring_p(&app_path, "objs");
			create_dir(app_path.str);
			free_string(&app_path);

			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			cat_cstring_p(&app_path, "layouts");
			create_dir(app_path.str);
			free_string(&app_path);

			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			cat_cstring_p(&app_path, "datas");
			create_dir(app_path.str);
			free_string(&app_path);

			make_string(&app_path, "apps");
			cat_cstring_p(&app_path, app_name.str);
			cat_cstring_p(&app_path, "modz");
			create_dir(app_path.str);
			free_string(&app_path);

			tree_manager_create_node		(app_name.str, 0x0B008000, &app_tx);
			tree_manager_copy_children_ref	(&app_tx, tx);
			add_app_tx						(&app_tx, app_name.str);
			release_zone_ref				(&app_tx);
			free_string						(&app_name);
		}
		else if (tree_manager_get_child_value_i32(tx, calc_crc32_c("app_item"), &app_item))
		{
			struct string	app_name = { 0 };
			mem_zone_ref	app = { (void *)0x00000000L };
			switch (app_item)
			{
				case 1:
					if(tree_manager_get_child_value_istr(tx, calc_crc32_c("appType"), &app_name, 0))
					{
						char			tchash[65];
						struct string	app_path = { 0 };
						n = 32;
						while (n--)
						{
							tchash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
							tchash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];
						}
						tchash[64] = 0;

	
						make_string							(&app_path, "apps");
						cat_cstring_p						(&app_path, app_name.str);
						cat_cstring_p						(&app_path, "types");
						cat_cstring_p						(&app_path, tchash);
						put_file							(app_path.str, buffer, length);
						free_string							(&app_path);

						if (tree_node_find_child_by_name(&apps, app_name.str, &app))
						{
							add_app_tx_type	(&app, tx);
							release_zone_ref(&app);
						}
					}
					free_string(&app_name);
				break;
				case 2:
					if (tree_manager_get_child_value_istr(tx, calc_crc32_c("appObj"), &app_name, 0))
					{
						char			tchash[65];
						char			typeStr[16];
						mem_zone_ref	idxs = { 0 };
						struct string	app_path = { 0 };
						unsigned int	typeID;
						n = 32;
						while (n--)
						{
							tchash[n * 2 + 0] = hex_chars[tx_hash[n] >> 4];
							tchash[n * 2 + 1] = hex_chars[tx_hash[n] & 0x0F];
						}
						tchash[64] = 0;

						
						tree_manager_get_child_value_i32(tx, calc_crc32_c("objType"), &typeID);

						uitoa_s(typeID, typeStr, 16, 16);


						make_string			(&app_path, "apps");
						cat_cstring_p		(&app_path, app_name.str);
						cat_cstring_p		(&app_path, "objs");
						cat_cstring_p		(&app_path, tchash);
						put_file			(app_path.str, buffer, length);
						free_string			(&app_path);

						make_string			(&app_path, "apps");
						cat_cstring_p		(&app_path, app_name.str);
						cat_cstring_p		(&app_path, "objs");
						cat_cstring_p		(&app_path, typeStr);
						append_file			(app_path.str, tx_hash, 32);
						free_string			(&app_path);

						add_index			(app_name.str, typeStr, "time", tx_time, tx_hash);


						if (tree_manager_create_node("idxs", 0x09000001, &idxs))
						{
							mem_zone_ref		m_idlist = { 0 }, obj = { 0 };
							mem_zone_ref_ptr	idx = (void *)0x00000000L;
					
							tree_manager_find_child_node(tx, calc_crc32_c("objDef"), typeID, &obj);
							

							get_app_type_idxs	(app_name.str, typeID, &idxs);


							for (tree_manager_get_first_child(&idxs, &m_idlist, &idx); ((idx != (void *)0x00000000) && (idx->zone != (void *)0x00000000)); tree_manager_get_next_child(&m_idlist, &idx))
							{
								const char *id_name;
								id_name = tree_mamanger_get_node_name(idx);
								switch (tree_mamanger_get_node_type(idx))
								{
									case 0x00000002:
									{
										unsigned int val;
										tree_manager_get_child_value_i32(&obj, calc_crc32_c(id_name), &val);
										add_index						(app_name.str, typeStr, id_name, val, tx_hash);
									}
									break;
									case 0x0B000100:
									{
										struct string val = { 0 };
										tree_manager_get_child_value_istr	(&obj, calc_crc32_c(id_name), &val,0);
										add_index_str						(app_name.str, typeStr, id_name, &val, tx_hash);
									}
									break;
								}
							}

							release_zone_ref	(&idxs);
						}

					}
					free_string(&app_name);
				break;
				case 3:
					if (tree_manager_get_child_value_istr(tx, calc_crc32_c("appFile"), &app_name, 0))
					{
						mem_zone_ref file = { (void *)0x00000000L };

						if (tree_manager_find_child_node(tx, calc_crc32_c("fileDef"), 0x00000400, &file))
						{
							unsigned char	buffer[64];
							if (tree_manager_get_child_value_hash(&file, calc_crc32_c("dataHash"), buffer))
							{
								struct string	app_path = { 0 };

								memcpy_c		(&buffer[32], tx_hash, sizeof(hash_t));
								make_string		(&app_path, "apps");
								cat_cstring_p	(&app_path, app_name.str);
								cat_cstring_p	(&app_path, "datas");
								cat_cstring_p	(&app_path, "index");

								if (stat_file(app_path.str)==0)
									append_file		(app_path.str, buffer, 64);
								else
									put_file		(app_path.str, buffer, 64);

								free_string		(&app_path);
							}
							release_zone_ref(&file);
						}
					}
				break;
				case 4:
					if (tree_manager_get_child_value_istr(tx, calc_crc32_c("appLayout"), &app_name, 0))
					{
						struct string	fileData = { 0 }, filename = { 0 };
						mem_zone_ref	file = { (void *)0x00000000L };

						ret = tree_manager_find_child_node(tx, calc_crc32_c("layoutDef"), 0x00000400, &file);
						if (ret)ret = tree_manager_get_child_value_istr(&file, calc_crc32_c("filedata"), &fileData, 0);
						if (ret)ret = tree_manager_get_child_value_istr(&file, calc_crc32_c("filename"), &filename, 0);
						if (ret)
						{
							struct string	app_path = { 0 };

							make_string		(&app_path, "apps");
							cat_cstring_p	(&app_path, app_name.str);
							cat_cstring_p	(&app_path, "layouts");
							cat_cstring_p	(&app_path, filename.str);
							put_file		(app_path.str, fileData.str, fileData.len);
							free_string		(&app_path);
						}
						release_zone_ref(&file);
						
					}
				break;
				case 5:
					if (tree_manager_get_child_value_istr(tx, calc_crc32_c("appModule"), &app_name, 0))
					{
						struct string	fileData = { 0 }, filename = { 0 };
						mem_zone_ref	file = { (void *)0x00000000L }, scripts = { (void *)0x00000000L }, script = { (void *)0x00000000L };

						ret = tree_manager_find_child_node(tx, calc_crc32_c("moduleDef"), 0x00000400, &file);
						if (ret)ret = tree_manager_get_child_value_istr(&file, calc_crc32_c("filedata"), &fileData, 0);
						if (ret)ret = tree_manager_get_child_value_istr(&file, calc_crc32_c("filename"), &filename, 0);
						if (ret)
						{
							struct string	app_path = { 0 };
							char *cappn;
							make_string		(&app_path, "apps");
							cat_cstring_p	(&app_path, app_name.str);
							cat_cstring_p	(&app_path, "modz");
							cat_cstring_p	(&app_path, filename.str);
							put_file		(app_path.str, fileData.str, fileData.len);
							
							*cappn=app_name.str;

							tree_manager_find_child_node(&apps, calc_crc32_c(cappn), 0x0B008000, &app);

							if ((filename.len >= 5) && (!strncmp_c(&filename.str[filename.len-5],".site",5)))
							{
								get_app_scripts				(&app, &scripts);
								tree_remove_child_by_name	(&scripts, calc_crc32_c(filename.str));
								release_zone_ref			(&scripts);

								if (load_script(app_path.str, filename.str, &script, 1))
								{
									ctime_t ftime;
									get_ftime						(app_path.str, &ftime);
									tree_manager_write_node_dword	(&script, 0, ftime);
									add_app_script					(&app, &script);
									release_zone_ref				(&script);
								}
							}
						
							release_zone_ref			(&app);
							free_string					(&app_path);
						}


						release_zone_ref(&file);
					}
				break;
			}
		}
		else if (tree_manager_get_child_value_hash(tx, calc_crc32_c("appChildOf"), pObjHash))
		{
			char			pObj[65];
			hash_t			child_obj;
			mem_zone_ref	obj = { (void *)0x00000000L };
			struct string   child_path = { (void *)0x00000000L };
			char			key[32];

			tree_manager_get_child_value_str (tx,  calc_crc32_c("appChildKey"), key,32,16);
			tree_manager_get_child_value_hash(tx,  calc_crc32_c("newChild"), child_obj);
			tree_manager_get_child_value_istr(tx,  calc_crc32_c("appChild"), &app_name,0);

			n = 0;
			while (n<32)
			{
				pObj[n * 2 + 0] = hex_chars[pObjHash[n] >> 4];
				pObj[n * 2 + 1] = hex_chars[pObjHash[n] & 0x0F];
				n++;
			}
			pObj[64] = 0;

			make_string  (&child_path, "apps");
			cat_cstring_p(&child_path, app_name.str);
			cat_cstring_p(&child_path, "objs");
			cat_cstring_p(&child_path, pObj);
			cat_cstring  (&child_path, "_");
			cat_cstring	 (&child_path, key);

			append_file	 (child_path.str, child_obj, 32);

			free_string	 (&child_path);
			free_string	 (&app_name);
		}

				
		store_tx_blk_index	(tx_hash,blk_hash,height,tx_ofset,tx_time);
		append_file			(blk_data_path.str, &length,4);
		append_file			(blk_data_path.str, buffer, length);
		free_c				(buffer);
		
		tx_ofset += length + 4;

		if (is_tx_null(tx) == 1)
			continue;

		if(is_app_root(tx))
		{
			blk_store_app_root	(tx);
			set_root_app		(tx);
		}
		else
		{
			ret = store_tx_inputs(tx);
			if (ret)ret = store_tx_outputs(tx);
		}

		if (!ret)
		{
			dec_zone_ref	(tx);
			release_zone_ref(&my_list);
			break;
		}
	}

	free_string		(&blk_data_path);
	free_string		(&blk_path);

	return ret;
}



