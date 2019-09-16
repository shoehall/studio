# 日期格式模式 说明

d 月中的某一天。一位数的日期没有前导零。
dd 月中的某一天。一位数的日期有一个前导零。
ddd 周中某天的缩写名称，在 AbbreviatedDayNames 中定义。
dddd 周中某天的完整名称，在 DayNames 中定义。
M 月份数字。一位数的月份没有前导零。
MM 月份数字。一位数的月份有一个前导零。
MMM 月份的缩写名称，在 AbbreviatedMonthNames 中定义。
MMMM 月份的完整名称，在 MonthNames 中定义。
y 不包含纪元的年份。如果不包含纪元的年份小于 10，则显示不具有前导零的年份。
yy 不包含纪元的年份。如果不包含纪元的年份小于 10，则显示具有前导零的年份。
yyyy 包括纪元的四位数的年份。
gg 时期或纪元。如果要设置格式的日期不具有关联的时期或纪元字符串，则忽略该模式。
h 12 小时制的小时。一位数的小时数没有前导零。
hh 12 小时制的小时。一位数的小时数有前导零。
H 24 小时制的小时。一位数的小时数没有前导零。
HH 24 小时制的小时。一位数的小时数有前导零。
m 分钟。一位数的分钟数没有前导零。
mm 分钟。一位数的分钟数有一个前导零。
s 秒。一位数的秒数没有前导零。
ss 秒。一位数的秒数有一个前导零。
f 秒的小数精度为一位。其余数字被截断。
ff 秒的小数精度为两位。其余数字被截断。
fff 秒的小数精度为三位。其余数字被截断。
ffff 秒的小数精度为四位。其余数字被截断。
fffff 秒的小数精度为五位。其余数字被截断。
ffffff 秒的小数精度为六位。其余数字被截断。
fffffff 秒的小数精度为七位。其余数字被截断。
t 在 AMDesignator 或 PMDesignator 中定义的 AM/PM 指示项的第一个字符（如果存在）。
tt 在 AMDesignator 或 PMDesignator 中定义的 AM/PM 指示项（如果存在）。
z 时区偏移量（“+”或“-”后面仅跟小时）。一位数的小时数没有前导零。例如，太平洋标准时间是“-8”。
zz 时区偏移量（“+”或“-”后面仅跟小时）。一位数的小时数有前导零。例如，太平洋标准时间是“-08”。
zzz 完整时区偏移量（“+”或“-”后面跟有小时和分钟）。一位数的小时数和分钟数有前导零。例如，太平洋标准时间是“-08:00”。
: 在 TimeSeparator 中定义的默认时间分隔符。
/ 在 DateSeparator 中定义的默认日期分隔符。
% c 其中 c 是格式模式（如果单独使用）。如果格式模式与原义字符或其他格式模式合并，则可以省略“%”字符。
\ c 其中 c 是任意字符。照原义显示字符。若要显示反斜杠字符，请使用“\\”。

只有上面第二个表中列出的格式模式才能用于创建自定义模式；在第一个表中列出的标准格式字符不能用于创建自定义模式。
自定义模式的长度至少为两个字符；例如:
DateTime.ToString( “d”); // 返回 DateTime 值；“d”是标准短日期模式。
DateTime.ToString( “%d”); // 返回月中的某天；“%d”是自定义模式。
DateTime.ToString( “d “); // 返回后面跟有一个空白字符的月中的某天；“d”是自定义模式。


## 一些后缀
1.CST China Standard Time 中国标准时间
2.UTC 世界标准时间可以后缀时区 UTC+08等价于中国时间 Z
3.GMT 格林威治时间
4.Z


## 经验总结
东14区是有这样的时区的, 参考`世界时区`: http://www.shijian.cc/shiqu/

数值乘法的上溢和下溢以及示例
用于时间解析，技巧：除以（较大的数 除以 较小的数）：前提是整数，此时不需要转为Double，无精度损失。利用的先验信息是：precision肯定比1000和1000000小，且经常整除
```
def parser(time: Long): Timestamp = {
  // 通常情况下precision都是10的整个数倍, 且小于1000, 因此可以调换乘积顺序防止上溢
  val timeByMillis = if (1000.0 / precision == 1000 / precision) {
    println("整除")
    timeUnit match {
      case "second" => time * precision.toLong * 1000L
      case "millisecond" => time * precision.toLong
      case "microsecond" => time / (1000L / precision.toLong)
      case "nanosecond" => time / (1000000L / precision.toLong)
    }
  } else {
    // 未整除时, 顺序不能调换否则可能上溢(fileTimeUTC位数过大会上溢)
    timeUnit match {
      case "second" => time * precision.toLong * 1000L
      case "millisecond" => time * precision.toLong
      case "microsecond" => time / 1000L * precision.toLong
      case "nanosecond" => time / 1000000L * precision.toLong
    }
  }


  epochFormat.toLowerCase() match {
    case "utc" => new Timestamp(timeByMillis.toLong)
    case "filetimeutc" => new Timestamp(timeByMillis.toLong - 11644473600000L)
    case _ => throw new Exception("目前只支持utc | fileTimeUTC, 不计大小写")
  }
}

```



测试用例：
```
val time = new TimeWithLongParser()
  .setEPOCH(TimeWithLongParser.EPOCH_FORMAT.FILE_TIME_UTC)
  .setPrecision(100)
  .setTimeUnit(TimeWithLongParser.TIME_UNIT.NANOSECOND)
  .parser(129757574870723241L)
```

![道路图片](./road.jpg)

![avatar](./ret.jpg)

![avatar](./result.jpg)

如果不是这样会造成：fileTimeUTC（一般都已经接近Long的上限了），乘以100就超了




