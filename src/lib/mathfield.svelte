<script>
  import { onMount } from "svelte";
  import * as mathlive from 'mathlive'
  let mf;
  onMount(() => {
    if (mf) {
      mf.focus();
    }
  });
</script>

<math-field bind:this="{mf}"></math-field>

<style>
    math-field {
        border: 1px solid palegreen;
        padding: 0.5rem;
        font: inherit;
    }
</style>