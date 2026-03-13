<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Practice 4 - PHP Multiplication Table</title>
  <style>
    table,
    th,
    td {
      border: 1px solid black;
      border-collapse: collapse;
      padding: 8px;
      text-align: center;
    }

    th {
      background-color: #dddddd;
    }
  </style>
</head>

<body>
  <h1>PHP Multiplication Table</h1>

  <form method="post" action="">
    <label for="number">Enter a number:</label>
    <input type="number" name="number" id="number" min="1" required>
    <input type="submit" value="Generate Table">
  </form>

  <br>

  <?php
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $n = intval($_POST["number"]);

      echo "<table>";
      echo "<tr><th></th>";

      for ($i = 1; $i <= $n; $i++) {
          echo "<th>$i</th>";
      }
      echo "</tr>";

      for ($row = 1; $row <= $n; $row++) {
          echo "<tr>";
          echo "<th>$row</th>";

          for ($col = 1; $col <= $n; $col++) {
              $product = $row * $col;
              echo "<td>$product</td>";
          }

          echo "</tr>";
      }

      echo "</table>";
  }
  ?>
</body>

</html>