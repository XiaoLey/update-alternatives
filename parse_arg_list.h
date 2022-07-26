/**
 * @file      parse_arg_list.h
 * @brief     参数列表解析
 * @details   各种用于解析参数和参数列表的函数
 * @author    黎逍(xiao.ley\@outlook.com)
 * @date      2022-07-24
 * @version   1.0
 * @copyright Copyright (c) 2022 Xiao Ley
 **********************************************************************************
 * @par 修改日志:
 * <table>
 * <tr><th>Date         <th>Version  <th>Author   <th>Description</tr>
 * <tr><td>2022-07-24   <td>1.0      <td>黎逍     <td>创建初始版本</tr>
 * </table>
 **********************************************************************************
 */

#ifndef UPDATE_ALTERNATIVES_PARSE_ARG_LIST_H__
#define UPDATE_ALTERNATIVES_PARSE_ARG_LIST_H__

#include <stdbool.h>
#include <stddef.h>

/// 参数项
typedef struct
{
    char *arg;      ///< 参数标识
    char **values;  ///< 参数值
} ArgItem;


/**
 * @brief new一个 ArgItem 对象
 * @return 如果一切正常，将返回一个新的 ArgItem 对象
 */
ArgItem *ua_newArgItem();

/**
 * @brief 删除 ArgItem 对象
 * @param[in,out] item ArgItem 对象指针
 */
void ua_deleteArgItem(ArgItem *item);

/**
 * @brief 设置参数标识
 * @param[out] item ArgItem 对象指针
 * @param[in] sign 参数标识
 */
void ua_setArgSign(ArgItem *item, const char *sign);

/**
 * @brief 设置参数值
 * @param[out] item ArgItem 对象指针
 * @param[in] value 参数值
 * @retval true 添加参数成功
 * @retval false 添加参数失败
 */
bool ua_addArgValue(ArgItem *item, const char *value);

/// 获取参数值的数量
inline size_t us_getArgValueSize(const ArgItem *item);

#endif  // UPDATE_ALTERNATIVES_PARSE_ARG_LIST_H__
