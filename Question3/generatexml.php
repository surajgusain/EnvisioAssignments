<?php
require("dbinfo.php");

// Start XML file, create parent node
$dom = new DOMDocument("1.0");
$node = $dom->createElement("markers");
$parnode = $dom->appendChild($node);

// Opens a connection to a mySQL server
$connection= new mysqli("localhost", "root", "", "db_locations");
if (!$connection) {
  die("Not connected : " . mysql_error());
}

$query = "SELECT * from locations";

// Search the rows in the markers table
$result = mysqli_query($connection, $query);

if (!$result) {
  die("Invalid query: " . mysql_error());
}

$resultArr = $result->fetch_assoc();

header("Content-type: text/xml");

// Iterate through the rows, adding XML nodes for each
while ($row = $resultArr){
  $node = $dom->createElement("marker");
  $newnode = $parnode->appendChild($node);
  $newnode->setAttribute("lat", $row['lat']);
  $newnode->setAttribute("lon", $row['lon']);
}

echo $dom->saveXML();
?>
