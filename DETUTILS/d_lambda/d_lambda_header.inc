/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Provides lambda functions,
 *   small functions used in expressions,
 *   such as conditions, calls, etc.
 *
 *
 */

/*
                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      
*/

stock _D_LAMBDA_for__(const function[], range)
{
	if(range <= 0)
	{
		__DETUtilsInfo("'lambda for' returned 'LAMBDA_FAIL'.",);
		return LAMBDA_FAIL;
	}
	new func[32];
	format(func, 32, "@D_LM_%s", function);
	if(funcidx(func) == -1)
	{
		__DETUtilsInfo("'lambda for' returned 'LAMBDA_FAIL'.",);
		return LAMBDA_FAIL;
	}
	for(new _D_LAMBDA_inline_loop; 
		_D_LAMBDA_inline_loop < range; 
		_D_LAMBDA_inline_loop++)
	{
		CallLocalFunction(func, "");
	}
	__DETUtilsInfo("'lambda for' returned 'LAMBDA_SUCCESS'.",);
	return LAMBDA_SUCCESS;
}

stock _D_LAMBDA_while__(const function[], bool:condition)
{
	if(condition == false)
	{
		__DETUtilsInfo("'lambda while' returned 'LAMBDA_FAIL'.",);
		return LAMBDA_FAIL;
	}
	new func[32];
	format(func, 32, "@D_LM_%s", function);
	if(funcidx(func) == -1)
	{
		__DETUtilsInfo("'lambda while' returned 'LAMBDA_FAIL'.",);
		return LAMBDA_FAIL;
	}
	do
	{
		CallLocalFunction(func, "");
	}
	while(
		condition
	);
	__DETUtilsInfo("'lambda while' returned 'LAMBDA_SUCCESS'.",);
	return LAMBDA_SUCCESS;
}

stock _D_LAMBDA_using__(const function[])
{
	new func[32];
	format(func, 32, "@D_LM_%s", function);
	if(funcidx(func) == -1)
	{
		__DETUtilsInfo("'lambda using' returned 'LAMBDA_FAIL'.",);
		return LAMBDA_FAIL;
	}
	CallLocalFunction(func, "");
	__DETUtilsInfo("'lambda using' returned 'LAMBDA_SUCCESS'.",);
	return LAMBDA_SUCCESS;
}