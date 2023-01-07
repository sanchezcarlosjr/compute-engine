<script>
  import "../app.css";
  import Cell from '$lib/cell.svelte';
  import * as app from "$lib/app";
  let instancePromise = app.startApp();
</script>

<div class="flex flex-row justify-center mt-6">
  <div class="flex flex-col w-3/6">
    <h1 class="text-3xl text-center">Alpha</h1>
    {#await instancePromise}
      <p>waiting...</p>
    {:then module}
      <Cell alpha={module}/>
    {:catch error}
      <p style="color: red">{error.message}</p>
    {/await}
  </div>
</div>




