## Application for the ANTLR 4 C++ target

This app shows how to build the ANTLR runtime both as dynamic and static library and how to use a parser generated from a simple demo grammar.

A few steps are necessary to get this to work:

- Download the current ANTLR jar and place it in this folder.
- Open the generation script for your platform (generate.cmd for Windows, generate.sh for *nix/OSX) and update the LOCATION var to the actual name of the jar you downloaded.
- Run the generation script. This will generate a test parser + lexer, along with listener + visitor classes in a subfolder named "generated". This is where the demo application looks for these files.
- Open the project in the folder that matches your system.
- Compile and run.

Compilation is done as described in the [runtime/cpp/readme.md](../README.md) file.

Only the windows target works now.

Parse preprocessed C files from a Nodix module, and track all access to nodes.

parsing 'src\block_adx\block.i' 

parsing 'src\block_adx\store.i' 

function load_sign_module 

	get : mod_def->"file" as str 

	set : mod_def->"mod_ptr" as ptr 

	call tree_mamanger_get_node_name on mod_def 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function init_blocks 

	get : node_config->"pubKeyVersion" as i32 

	get : node_config->"block_version" as i32 

	use : node_config->"sign_mod" as 0x08000008 

	use : node_config->"mining" as 0xFFFFFFFF 

	used key get : node_config->"mining"->"limit" as i32 

	used key get : node_config->"mining"->"targettimespan" as i32 

	used key get : node_config->"mining"->"targetspacing" as i32 

	used key get : node_config->"mining"->"maxtargetspacing" as i32 

	used key get : node_config->"mining"->"reward" as i64 

	used key get : node_config->"mining"->"last_pow_block" as i64 

	used key get : node_config->"mining"->"reward_halving" as i32 

	call load_sign_module on node_config->mod_def 

	call release_zone_ref on node_config->mod_def 

	call release_zone_ref on node_config->mining_conf 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_find_last_pow_block 

	get : pindex->"height" as i64 

	get : pindex->"blkHash" as str 

	get : pindex->"prev" as str 

	get : pindex->"time" as i32 

	call load_blk_hdr on pindex 

	call load_blk_hdr on pindex 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function add_app_tx 

	set : new_app->"appName" as str 

	set : new_app->"appAddr" as btcaddr 

	use : new_app->"txsout" as 0x0B080000 

	used key enum : new_app->"txsout"->[*]->out

	used key get : new_app->"txsout"->out[*]."script" as istr 

	used key set : new_app->"txsout"->out[*]."app_item" as i32 

	use : new_app->"appAddr" as 0x0B009000 

	call release_zone_ref on new_app->txout_list 

	call tree_manager_node_add_child on new_app 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_apps 

	call copy_zone_ref on Apps 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function set_root_app 

	call compute_tx_hash on tx 

	call get_tx_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_root_app 

	call tree_manager_write_node_hash on rootAppHash 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_root_app_addr 

	call tree_manager_write_node_btcaddr on rootAppAddr 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_root_app_fee 

	call tree_manager_write_node_qword on rootAppFees 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_pow_reward 

	call tree_manager_write_node_qword on Reward 

	call tree_mamanger_get_node_dword on height 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function tx_add_input 

	use : tx->"txsin" as 0x0B010000 

	call tree_manager_node_add_child on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function tx_add_output 

	use : tx->"txsout" as 0x0B080000 

	call tree_manager_node_add_child on tx->txout_list 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function new_transaction 

	set : tx->"version" as i32 

	set : tx->"time" as i32 

	set : tx->"locktime" as i32 

	set : tx->"submitted" as i32 

	add : tx->"txsin" as 0x0B010000 

	add : tx->"txsout" as 0x0B080000 

	call tree_manager_create_node on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function parse_approot_tx 

	set : tx->"dstaddr" as btcaddr 

	use : tx->"txsout" as 0x0B080000 

	call tree_manager_get_child_at on tx->txout_list 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_approot_tx 

	set : tx->"is_app_root" as i32 

	set : tx->"txid" as hash 

	call new_transaction on tx 

	call tx_add_input on tx 

	call tx_add_output on tx 

	call compute_tx_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_app_tx 

	set : tx->"txid" as hash 

	call new_transaction on tx 

	call tx_add_input on tx 

	call get_tx_input on tx 

	call tx_add_output on tx 

	call tx_add_output on tx 

	call tx_add_output on tx 

	call tx_add_output on tx 

	call tx_add_output on tx 

	call compute_tx_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_app_item_tx 

	set : tx->"app_item" as i32 

	set : tx->"txid" as hash 

	call new_transaction on tx 

	call tx_add_input on tx 

	call get_tx_input on tx 

	call compute_tx_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_app_child_obj_tx 

	call new_transaction on tx 

	call tx_add_input on tx 

	call get_tx_input on tx 

	call tx_add_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function compute_tx_hash 

	set : tx->"size" as i32 

	call get_node_size on tx 

	call write_node on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function compute_block_pow 

	call get_node_size on block 

	call write_node on block 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function compute_block_hash 

	call get_node_size on block 

	call write_node on block 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function set_block_hash 

	set : block->"blkHash" as bhash 

	call compute_block_hash on block 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_hash_list_from_tx 

	call tree_manager_write_node_hash on hashes 

	enum : txs->[*] 

	enum set : txs->[*]->"txid" as hash 

	call tree_manager_get_next_child on txs->tx 

	call compute_tx_hash on txs->tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function compute_merkle_round 

	call tree_manager_get_node_hash on hashes 

	call tree_manager_get_node_hash on hashes 

	call tree_manager_write_node_hash on hashes 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function build_merkel_tree 

	call get_hash_list_from_tx on txs 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function block_compute_pow_target 

	call tree_mamanger_get_node_dword on nBits 

	call tree_manager_write_node_dword on nBits 

	call tree_manager_write_node_dword on nBits 

	call tree_mamanger_get_node_dword on ActualSpacing 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_input 

	call tree_manager_get_child_at on vin 

	use : tx->"txsin" as 0x0B010000 

	call tree_manager_get_child_at on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_output 

	call tree_manager_get_child_at on vout 

	use : tx->"txsout" as 0x0B080000 

	call tree_manager_get_child_at on tx->txout_list 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_tx_input 

	call load_tx on tx_out 

	get : in->"txid" as hash 

	call get_tx_input on in 

	call release_zone_ref on in 

	call get_tx_input on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_blk_tx_input 

	call get_tx_output on vout 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_tx_input_vout 

	call get_tx_output on vout 

	call load_tx_input on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function is_coinbase 

	use : tx->"txsin" as 0x0B010000 

	call tree_manager_get_child_at on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_input_hash 

	use : tx->"txsin" as 0x0B010000 

	call tree_manager_get_child_at on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_output_amount 

	call get_tx_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function dump_tx_infos 

	call load_tx_input on tx 

	call compute_tx_sign_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function is_vout_null 

	call get_tx_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function create_null_tx 

	call new_transaction on tx 

	call tx_add_input on tx 

	call tx_add_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function is_tx_null 

	use : tx->"txsout" as 0x0B080000 

	call tree_manager_get_node_num_children on tx->txout_list 

	call release_zone_ref on tx->txout_list 

	call tree_manager_get_child_at on tx->txout_list 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_hash_list 

	set : hash_list->"hash" as bhash 

	call tree_manager_create_node on hash_list 

	enum : hdr_list->[*] 

	enum get : hdr_list->[*]->"blkHash" as hash 

	call tree_manager_get_next_child on hdr_list->hdr 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function compute_tx_sign_hash 

	call tree_manager_node_dup on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_tx_input_sig 

	get : tx->"txid" as str 

	call load_tx_input on tx 

	call log_message on tx 

	call compute_tx_sign_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function tx_sign 

	call get_tx_input on tx 

	call get_tx_output on tx 

	call compute_tx_sign_hash on tx 

	call load_tx_input_vout on tx 

	call compute_tx_sign_hash on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_types 

	use : app->"txsout" as 0x0B080000 

	used key enum : app->"txsout"->[*]->out

	used key get : app->"txsout"->out[*]."app_item" as i32 

	call release_zone_ref on app->txout_list 

	call release_zone_ref on app->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_scripts 

	use : app->"txsout" as 0x0B080000 

	used key enum : app->"txsout"->[*]->out

	used key get : app->"txsout"->out[*]."app_item" as i32 

	call release_zone_ref on app->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function add_app_tx_type 

	set : typetx->"typeName" as vstr 

	set : typetx->"typeId" as i32 

	call get_tx_output on typetx 

	call tree_manager_node_add_child on typetx 

	use : app->"txsout" as 0x0B080000 

	used key enum : app->"txsout"->[*]->out

	used key get : app->"txsout"->out[*]."app_item" as i32 

	call release_zone_ref on app->txout_list 

	call release_zone_ref on app->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function add_app_script 

	call tree_manager_node_add_child on script_vars 

	use : app->"txsout" as 0x0B080000 

	used key enum : app->"txsout"->[*]->out

	used key get : app->"txsout"->out[*]."app_item" as i32 

	call release_zone_ref on app->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function is_app_root 

	use : tx->"txsin" as 0x0B010000 

	used key enum : tx->"txsin"->[*]->input

	used key get : tx->"txsin"->input[*]."txid" as hash 

	used key get : tx->"txsin"->input[*]."idx" as i32 

	used key get : tx->"txsin"->input[*]."script" as istr 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function tx_is_app_item 

	call tree_find_child_node_by_member_name_hash on app_tx 

	call get_tx_output on app_tx 

	call release_zone_ref on app_tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function tx_is_app_file 

	call get_script_file on file 

	call get_tx_input on tx 

	call get_tx_output on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_file 

	add : hash_list->"file" as 0x0A000080 

	call tree_manager_write_node_hash on hash_list->new_file 

	call release_zone_ref on hash_list->new_file 

	get : tx->"txid" as hash 

	use : tx->"fileDef" as 0x00000400 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function obj_new 

	add : obj->KeyName as KeyId 

	call tree_manager_create_node on obj 

	call unserialize_children on obj 

	get : type->"typeId" as i32 

	use : type->"txsout" as 0x0B080000 

	used key enum : type->"txsout"->[*]->key

	used key get : type->"txsout"->key[*]."value" as i64 

	used key get : type->"txsout"->key[*]."script" as istr 

	call release_zone_ref on type->type_outs 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function is_obj_child 

	call tree_find_child_node_by_member_name_hash on prev_tx 

	call load_tx on prev_tx 

	call get_tx_input on prev_tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_type_idxs 

	add : keys->KeyName as KeyId 

	call tree_manager_write_node_dword on keys->nk 

	call release_zone_ref on keys->nk 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_app_obj_unique 

	get : obj->KeyName as istr 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_tx_inputs 

	set : tx->"AppName" as str 

	set : tx->"app_item" as i32 

	set : tx->"appType" as vstr 

	set : tx->"appLayout" as vstr 

	set : tx->"appModule" as vstr 

	set : tx->"appObj" as vstr 

	set : tx->"ObjSign" as vstr 

	set : tx->"app_item" as i32 

	set : tx->"appFile" as vstr 

	set : tx->"app_item" as i32 

	set : tx->"pObjSigned" as bool 

	set : tx->"pObjType" as i32 

	set : tx->"appChild" as vstr 

	set : tx->"appChildOf" as hash 

	use : tx->"txsin" as 0x0B010000 

	used key enum : tx->"txsin"->[*]->input

	used key get : tx->"txsin"->input[*]."txid" as hash 

	used key get : tx->"txsin"->input[*]."idx" as i32 

	used key get : tx->"txsin"->input[*]."script" as istr 

	used key get : tx->"txsin"->input[*]."script" as istr 

	used key get : tx->"txsin"->input[*]."script" as istr 

	used key get : tx->"txsin"->input[*]."script" as istr 

	used key get : tx->"txsin"->input[*]."script" as istr 

	used key set : tx->"txsin"->input[*]."isApp" as bool 

	used key set : tx->"txsin"->input[*]."appName" as str 

	used key set : tx->"txsin"->input[*]."srcapp" as vstr 

	used key set : tx->"txsin"->input[*]."srcaddr" as btcaddr 

	used key set : tx->"txsin"->input[*]."srcaddr" as btcaddr 

	used key set : tx->"txsin"->input[*]."value" as i64 

	used key set : tx->"txsin"->input[*]."srcapp" as vstr 

	used key set : tx->"txsin"->input[*]."srcaddr" as btcaddr 

	used key set : tx->"txsin"->input[*]."value" as i64 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

	call compute_tx_sign_hash on tx 

	call tree_manager_node_add_child on tx 

	call release_zone_ref on tx->txin_list 

	call compute_tx_sign_hash on tx 

	call compute_tx_sign_hash on tx 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_tx_outputs 

	get : tx->"app_root_amnt" as i64 

	get : tx->"app_item" as i32 

	get : tx->"appObj" as str 

	get : tx->"ObjSign" as istr 

	get : tx->"appChildOf" as hash 

	get : tx->"pObjSigned" as i32 

	get : tx->"pObjType" as i32 

	get : tx->"appChild" as istr 

	set : tx->"app_root_amnt" as i64 

	set : tx->"objType" as i32 

	set : tx->"fileHash" as hash 

	set : tx->"appChildKey" as vstr 

	set : tx->"newChild" as hash 

	use : tx->"txsout" as 0x0B080000 

	used key enum : tx->"txsout"->[*]->out

	used key get : tx->"txsout"->out[*]."value" as i64 

	used key get : tx->"txsout"->out[*]."script" as istr 

	used key get : tx->"txsout"->out[*]."script" as istr 

	used key set : tx->"txsout"->out[*]."dstaddr" as btcaddr 

	use : tx->"AppName" as 0x00000001 

	use : tx->"AppName" as 0x00000001 

	call compute_tx_sign_hash on tx 

	call tree_manager_node_add_child on tx 

	call tree_manager_node_add_child on tx 

	call tree_manager_node_add_child on tx 

	call tree_manager_node_add_child on tx 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function find_inputs 

	enum : tx_list->[*] 

	call tree_manager_get_next_child on tx_list->tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_tx_list 

	enum : tx_list->[*] 

	enum get : tx_list->[*]->"app_root_amnt" as i64 

	call build_merkel_tree on tx_list 

	call is_tx_null on tx_list->tx 

	call tree_manager_get_next_child on tx_list->tx 

	call tree_manager_get_next_child on tx_list->tx 

	call is_tx_null on tx_list->tx 

	call is_app_root on tx_list->tx 

	call check_tx_inputs on tx_list->tx 

	call check_tx_outputs on tx_list->tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function check_block_pow 

	get : hdr->"blkHash" as hash 

	get : hdr->"blk pow" as hash 

	set : hdr->"blkHash" as bhash 

	set : hdr->"blk pow" as hash 

	call compute_block_hash on hdr 

	call compute_block_pow on hdr 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_prev_block_time 

	get : header->"prev" as str 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function block_has_pow 

	call tree_manager_get_node_str on blockHash 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_iadix_merkle 

	call tree_manager_node_add_child on txs 

	call build_merkel_tree on txs 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function make_genesis_block 

	set : genesis->"merkle_root" as hash 

	set : genesis->"prev" as hash 

	set : genesis->"version" as i32 

	set : genesis->"time" as i32 

	set : genesis->"bits" as i32 

	set : genesis->"nonce" as i32 

	set : genesis->"blkHash" as bhash 

	set : genesis->"blk pow" as hash 

	set : genesis->"StakeMod" as i64 

	set : genesis->"StakeMod2" as hash 

	call tree_manager_create_node on genesis 

	call make_iadix_merkle on genesis 

	call tree_manager_node_add_child on genesis 

	call compute_block_pow on genesis 

	call store_block on genesis 

	get : genesis_conf->"merkle_root" as hash 

	get : genesis_conf->"version" as i32 

	get : genesis_conf->"time" as i32 

	get : genesis_conf->"bits" as i32 

	get : genesis_conf->"nonce" as i32 

	get : genesis_conf->"InitialStakeModifier" as i64 

	get : genesis_conf->"InitialStakeModifier2" as hash 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_tx_data 

	set : txData->"data" as vstr 

	set : txData->"fee" as i64 

	set : txData->"hash" as hash 

	set : txData->"required" as bool 

	get : tx->"size" as i32 

	get : tx->"fee" as i64 

	get : tx->"txid" as hash 

	call write_node on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_load_tx_ofset 

	set : tx->"size" as i32 

	set : tx->"txid" as hash 

	call tree_manager_create_node on tx 

	call read_node on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_tx 

	get : tx->"txid" as hash 

	call blk_load_tx_ofset on tx 

	call log_message on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_tx_addresses 

	add : tx_hashes->"tx" as 0x0B001000 

	call tree_manager_write_node_hash on tx_hashes->new_hash 

	call release_zone_ref on tx_hashes->new_hash 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function store_tx_vout 

	call tree_manager_get_child_at on txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function rm_app_file 

	get : file->"dataHash" as hash 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function cancel_tx_outputs 

	get : tx->"txid" as str 

	get : tx->"txid" as str 

	get : tx->"is_app_item" as i32 

	get : tx->"appName" as str 

	get : tx->"txid" as hash 

	get : tx->"objChild" as str 

	get : tx->"appChildOf" as str 

	set : tx->"txid" as hash 

	use : tx->"txsout" as 0x0B080000 

	call compute_tx_hash on tx 

	call tree_manager_get_node_num_children on tx->txout_list 

	call get_tx_output_amount on tx 

	call get_tx_output on tx 

	call get_tx_output on tx 

	call get_tx_output on tx 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function cancel_tx_inputs 

	use : tx->"txsin" as 0x0B010000 

	used key enum : tx->"txsin"->[*]->input

	used key get : tx->"txsin"->input[*]."txid" as hash 

	used key get : tx->"txsin"->input[*]."idx" as i32 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_file 

	call get_script_file on file 

	call get_tx_input on file_tx 

	call get_tx_output on file_tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_files 

	add : files->"file" as 0x0B001000 

	call tree_manager_write_node_hash on files->newh 

	call release_zone_ref on files->newh 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_missing_files 

	add : files->"file" as 0x0A000080 

	call tree_manager_write_node_hash on files->newh 

	call release_zone_ref on files->newh 

	call tree_find_child_node_by_member_name_hash on pending 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_blk_txs 

	add : txs->"tx" as 0x0B001000 

	call tree_manager_write_node_hash on txs->tx 

	call release_zone_ref on txs->tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_blk_txs 

	add : txs->"tx" as 0x0B008000 

	added key set : txs->"tx"->"size" as i32 

	added key set : txs->"tx"->"txid" as hash 

	call init_node on txs->tx 

	call read_node on txs->tx 

	call release_zone_ref on txs->tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function store_tx_inputs 

	get : tx->"txid" as hash 

	set : tx->"txid" as hash 

	use : tx->"txsin" as 0x0B010000 

	used key enum : tx->"txsin"->[*]->input

	used key get : tx->"txsin"->input[*]."txid" as hash 

	used key get : tx->"txsin"->input[*]."idx" as i32 

	used key get : tx->"txsin"->input[*]."isObjChild" as i32 

	used key set : tx->"txsin"->input[*]."srcaddr" as btcaddr 

	used key set : tx->"txsin"->input[*]."amount" as i64 

	used key set : tx->"txsin"->input[*]."srcaddr" as btcaddr 

	call compute_tx_hash on tx 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

	call release_zone_ref on tx->txin_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function store_tx_outputs 

	get : tx->"txid" as hash 

	get : tx->"app_item" as i32 

	get : tx->"childOf" as i32 

	set : tx->"txid" as hash 

	use : tx->"txsout" as 0x0B080000 

	use : tx->"AppName" as 0x00000001 

	call compute_tx_hash on tx 

	call tree_manager_dump_node_rec on tx 

	call tree_manager_get_node_num_children on tx->txout_list 

	call release_zone_ref on tx->txout_list 

	call tree_manager_get_child_at on tx->txout_list 

	call get_tx_output_amount on tx 

	call get_tx_output_amount on tx 

	call store_tx_vout on tx->txout_list 

	call release_zone_ref on tx->txout_list 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_blk_hdr 

	set : hdr->"blkHash" as bhash 

	set : hdr->"height" as i64 

	set : hdr->"ntx" as vint 

	set : hdr->"blk pow" as hash 

	set : hdr->"blk pos" as hash 

	use : hdr->"signature" as 0x0B800000 

	add : hdr->"signature" as 0x0B800000 

	call tree_manager_create_node on hdr 

	call read_node on hdr 

	call tree_manager_write_node_sig on hdr->sig 

	call tree_manager_write_node_sig on hdr->sig 

	call release_zone_ref on hdr->sig 

	call release_zone_ref on hdr->sig 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function store_block_txs 

	enum : tx_list->[*] 

	enum get : tx_list->[*]->"txid" as hash 

	call tree_manager_get_node_num_children on tx_list 

	call tree_manager_get_next_child on tx_list->tx 

	get : header->"blkHash" as str 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_load_app_types 

	call tree_mamanger_get_node_name on app 

	call add_app_tx_type on app 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_load_app_scripts 

	get : app->"appName" as istr 

	call add_app_script on app 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_load_apps 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function blk_store_app_root 

	call get_node_size on tx 

	call write_node on tx 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_obj_hashes 

	add : hash_list->"hash" as 0x0B001000 

	call tree_manager_write_node_hash on hash_list->hashn 

	call release_zone_ref on hash_list->hashn 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_type_obj_hashes 

	add : hash_list->"hash" as 0x0B001000 

	call tree_manager_write_node_hash on hash_list->hashn 

	call release_zone_ref on hash_list->hashn 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function get_app_type_last_objs_hashes 

	add : hash_list->"hash" as 0x0B001000 

	call tree_manager_write_node_hash on hash_list->hashn 

	call release_zone_ref on hash_list->hashn 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function find_app_type_obj 

	add : hash_list->"hash" as 0x0B001000 

	call tree_manager_write_node_hash on hash_list->hashn 

	call release_zone_ref on hash_list->hashn 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_obj_childs 

	add : objs->"hash" as 0x0B001000 

	call tree_manager_node_add_child on objs 

	call tree_manager_write_node_hash on objs->hashn 

	call release_zone_ref on objs->hashn 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function load_obj 

	set : obj->"objHash" as hash 

	set : obj->"time" as i32 

	enum : obj->[*] 

	enum : obj->[*] 

	call obj_new on obj 

	call tree_manager_get_next_child on obj->key 

	call tree_mamanger_get_node_type on obj->key 

	call tree_mamanger_get_node_data_ptr on obj->key 

	call tree_manager_copy_children_ref on obj->key 

	call tree_manager_get_next_child on obj->key 

	call tree_manager_get_next_child on obj->key 

	call tree_mamanger_get_node_type on obj->key 

	call tree_mamanger_get_node_type on obj->key 

	call tree_mamanger_get_node_name on obj->key 

	call tree_mamanger_get_node_name on obj->key 

	call load_obj_childs on obj->key 

	call load_obj_childs on obj->key 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

function store_block 

	enum : tx_list->[*] 

	enum get : tx_list->[*]->"txid" as hash 

	enum get : tx_list->[*]->"time" as i32 

	enum get : tx_list->[*]->"AppName" as istr 

	enum get : tx_list->[*]->"app_item" as i32 

	enum get : tx_list->[*]->"appType" as istr 

	enum get : tx_list->[*]->"appObj" as istr 

	enum get : tx_list->[*]->"objType" as i32 

	enum get : tx_list->[*]->"appFile" as istr 

	enum get : tx_list->[*]->"appLayout" as istr 

	enum get : tx_list->[*]->"appModule" as istr 

	enum get : tx_list->[*]->"appChildOf" as hash 

	enum get : tx_list->[*]->"appChildKey" as str 

	enum get : tx_list->[*]->"newChild" as hash 

	enum get : tx_list->[*]->"appChild" as istr 

	enum set : tx_list->[*]->"txid" as hash 

	call tree_manager_get_node_num_children on tx_list 

	call tree_manager_get_next_child on tx_list->tx 

	call get_node_size on tx_list->tx 

	call write_node on tx_list->tx 

	call tree_manager_copy_children_ref on tx_list->tx 

	call add_app_tx_type on tx_list->tx 

	call is_tx_null on tx_list->tx 

	call is_app_root on tx_list->tx 

	call store_tx_inputs on tx_list->tx 

	call store_tx_outputs on tx_list->tx 

	get : header->"blkHash" as hash 

	get : header->"signature" as istr 

	get : header->"blk pow" as hash 

	get : header->"time" as i32 

	call write_node on header 

+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

