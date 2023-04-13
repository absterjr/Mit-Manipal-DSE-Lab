import org.apache.spark.sql.{DataFrame, SparkSession}
import org.apache.spark.sql.functions._

val spark = SparkSession.builder()
                        .appName("MyApp")
                        .master("local")
                        .getOrCreate()

val data = Seq(("John", 25), ("Jane", 30), ("Bob", 20))
val rdd = sc.parallelize(data)
val df = rdd.toDF("name", "age")

// Example methods:
val filteredDF = df.filter(col("age") > 25)
val groupedDF = df.groupBy("age").agg(count("name"))
val joinedDF = df.join(filteredDF, Seq("age"), "left_outer")

filteredDF.show()
groupedDF.show()
joinedDF.show()

